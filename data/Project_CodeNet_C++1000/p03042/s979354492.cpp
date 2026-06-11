#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using L64 = int64_t;

/* {x,y}という表現で格納される[x^y] */
inline vector<pair<L64, int>> prime_factorize(L64 N) {
  vector<pair<L64, int>> res;
  for (int a = 2; a * a <= N; ++a) {
    if (N % a != 0) {
      continue;
    }
    int ex = 0;
    while (N % a == 0) {
      ex++;
      N /= a;
    }
    res.push_back({a, ex});
  }
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main(void) {
  int S;
  cin >> S;
  int up = S / 100;
  int low = S % 100;

  if ((1 <= up && up <= 12) && (1 <= low && low <= 12))
    cout << "AMBIGUOUS";
  else if (!(1 <= up && up <= 12) && (1 <= low && low <= 12))
    cout << "YYMM";
  else if ((1 <= up && up <= 12) && !(1 <= low && low <= 12))
    cout << "MMYY";
  else if (!(1 <= up && up <= 12) && !(1 <= low && low <= 12))
    cout << "NA";
  return 0;
}