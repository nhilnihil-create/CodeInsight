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
  int N, K;
  string S;
  cin >> N >> K >> S;
  if (S[K - 1] == 'A')
    S[K - 1] = 'a';
  else if (S[K - 1] == 'B')
    S[K - 1] = 'b';
  else if (S[K - 1] == 'C')
    S[K - 1] = 'c';
  cout << S;
  return 0;
}