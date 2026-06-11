#include <algorithm>
#include <cmath>
#include <iomanip>
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
  int N, K;
  double res = 0;
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    int count = 0;
    int a = i;
    while (a < K) {
      a *= 2;
      count++;
    }
    res += 1 / (pow(2, count));
  }
  res /= N;
  cout << fixed << setprecision(15) << res;
  return 0;
}