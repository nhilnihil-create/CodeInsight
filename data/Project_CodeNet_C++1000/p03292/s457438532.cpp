#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  vector<int> A;

  rep(i, 3) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  sort(A.begin(), A.end());

  cout << abs(A[1] - A[2]) + abs(A[0] - A[1]) << endl;

  return 0;
}
