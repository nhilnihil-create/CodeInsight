#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;

  S[K - 1] += 32;
  cout << S << endl;
  return 0;
}