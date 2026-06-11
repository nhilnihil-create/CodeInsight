#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b; cin >> a >> b;
  int ans = 0;
  for (int i=a; i<=b; i++) {
    string s1 = to_string(i);
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    if (s1 == s2) ans++;
  }
  cout << ans << endl;
  return 0;
}