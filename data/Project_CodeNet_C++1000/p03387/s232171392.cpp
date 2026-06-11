#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a,b,c; cin >> a >> b >> c;
  int m = max(a,max(b,c));
  int ans = 0;
  ans += (m - a) / 2;
  ans += (m - b) / 2;
  ans += (m - c) / 2;
  int n = (m-a)%2 + (m-b)%2 + (m-c)%2;
  if (n == 1) ans+=2;
  if (n == 2) ans+=1;
  cout << ans << endl;
  return 0;
}