// https://atcoder.jp/contests/abc076/tasks/abc076_b
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K;
  cin >> N >> K;

  int out = 1;
  rep(i, N) {
    if (out < K)
      out *= 2;
    else
      out += K;
  }

  cout << out;
  return 0;
}
