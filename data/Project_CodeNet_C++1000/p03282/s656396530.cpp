#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string S;
  ll K;
  cin >> S >> K;

  rep(i, S.size()) {
    if (i == K - 1) {
      cout << S[i] << endl;
      return 0;
    }
    if (S[i] != '1') {
      cout << S[i] << endl;
      return 0;
    }
  }

  return 0;
}