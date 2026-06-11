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
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int num_left = A + B;
  int num_right = C + D;

  if (num_left == num_right)
    cout << "Balanced" << endl;
  else if (num_left > num_right)
    cout << "Left" << endl;
  else
    cout << "Right" << endl;
}
