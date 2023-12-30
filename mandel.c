//usr/bin/clang "$0" && exec ./a.out
// mandelbrot
#include <stdio.h>

int RESOLUTION_X = 150;
int RESOLUTION_Y = 60;
double OUTPUT_RES_X = 3.5;
double OUTPUT_RES_Y = 2;
double OUTPUT_OFFSET_X = -2.5;
int OUTPUT_OFFSET_Y = -1;
int MAX_ITERATIONS=27;

int calc(double xi, double yi) {
    xi = xi/ RESOLUTION_X * OUTPUT_RES_X + OUTPUT_OFFSET_X;
    yi = yi / RESOLUTION_Y * OUTPUT_RES_Y + OUTPUT_OFFSET_Y;
    double x = 0.0;
    double y = 0.0;
    int iteration = 0;
    while( x*x + y*y < 4 && iteration < MAX_ITERATIONS) {
        double xtemp = x*x - y*y + xi;
        y = 2*x*y + yi;
        x = xtemp;
        iteration += 1;
    }
    return iteration;
}

char show(int value) {
    return  value <= 26 ? ('A' + value - 1) : ' ';
}

void draw_window(int w, int h) {
  for (int yi = 0; yi < h; yi++) {
    for (int xi = 0; xi < w; xi++) {
        char value = show(calc(xi, yi));
        printf("%c", value);
    }
    puts("");
  }
}

int main() {
  draw_window(RESOLUTION_X, RESOLUTION_Y);
}

