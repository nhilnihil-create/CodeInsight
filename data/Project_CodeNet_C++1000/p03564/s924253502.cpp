#include <stdio.h>

int main() {
  int X, Y, output = 1;
  scanf("%d %d", &X, &Y);
  for(int i = 0; i < X; i++) {
    (output+Y > output*2) ? output =output* 2 : output =output+Y;
  }
  printf("%d\n", output);
  return 0;
}