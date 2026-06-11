#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  char ans = '1';
  int i = 0;
  while(s[i] == '1' && i < (int)s.size()) i++;
  if (k > i) ans = s[i];
  cout << ans << endl;
  return 0;
}