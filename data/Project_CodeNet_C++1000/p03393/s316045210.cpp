#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >> s;
  vector<bool> dic(26, 0);
  int n = s.size();

  if(n < 26) {
    rep(i, n) {
      dic[s[i] - 'a'] = 1;
    }
    rep(i, 26) {
      if(!dic[i]) {
        cout << s << alphabet[i] << endl;
        return 0;
      }
    }

    cout << -1 << endl;
    return 0;
  }

  int iz = 0;
  rep(i, n) {
    if(s[i] == 'z') {
      iz = i;
      break;
    }
  }
  if(iz == 0) {
    cout << -1 << endl;
    return 0;
  }

  string b = s;
  next_permutation(s.begin(), s.end());
  rep(i, n) {
    cout << s[i];
    if(b[i] != s[i]) break;
  }
  cout << endl;
}
