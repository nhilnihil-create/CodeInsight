#include <math.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  int N;
  cin >> N;

  vector<int> V(N);
  vector<int> C(N);

  rep(i, N) { cin >> V.at(i); }
  rep(i, N) { cin >> C.at(i); }

  int ans = 0;

  rep(i, N) {
    if (V.at(i) > C.at(i)) {
      ans += V.at(i) - C.at(i);
    }
  }
  cout << ans << endl;
}
