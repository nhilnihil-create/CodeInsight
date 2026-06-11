#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  map<char,ll> m;
  vector<char> c = {'M', 'A', 'R', 'C', 'H'};
  ll ans = 0;
  rep(i,n) {
    string s; cin >> s;
    m[s[0]]++;
  }
  for (int i = 0; i<5; i++) {
    for (int j = i+1; j<5; j++) {
      for (int k = j+1; k<5; k++) {
        ans += m[c[i]] * m[c[j]] * m[c[k]];
      }
    }
  }
  cout << ans << endl;
  return 0;
}