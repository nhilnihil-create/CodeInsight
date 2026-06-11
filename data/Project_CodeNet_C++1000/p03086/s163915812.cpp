#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
#define inf 1000000000000000000
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  string s;
  cin >> s;
  ll n = s.size(), ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      ll res = j - i;
      for (int k = i; k < j; k++) {
        if (s[k] != 'A' && s[k] != 'C' && s[k] != 'G' && s[k] != 'T') res = 0;
      }
      chmax(ans, res);
    }
  }
  cout << ans << endl;
}