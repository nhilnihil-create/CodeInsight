#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int ans = 0;
  for (int i = 1; i < N; ++i) {
    string X = S.substr(0, i);
    string Y = S.substr(i);

    map<char, int> m;
    rep(j, X.size()) {
      m[X[j]] = 1;
    }

    int count = 0;
    rep(j, Y.size()) {
      if (m[Y[j]] == 1) {
        count++;
        m[Y[j]]++;
      }
    }

    ans = max(ans, count);
  }

  cout << ans << endl;
  
  return 0;
}