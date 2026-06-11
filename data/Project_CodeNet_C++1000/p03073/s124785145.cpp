#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  int sn = s.size();
  int a1 = 0,a2 = 0;
  rep(i,sn) {
    if ( i    % 2 != s[i] - '0') a1++;
    if ((i+1) % 2 != s[i] - '0') a2++;
  }
  cout << min(a1,a2) << endl;
  return 0;
}