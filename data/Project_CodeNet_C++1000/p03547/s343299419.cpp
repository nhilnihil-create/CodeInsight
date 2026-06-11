#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  char X, Y;
  cin >> X >> Y;

  if (X > Y)
    printf(">\n");
  else if (X == Y)
    printf("=\n");
  else
    printf("<");

  return 0;
}
