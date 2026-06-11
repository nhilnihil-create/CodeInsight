#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int d,n; cin>>d>>n;
  int ans=n;
  if (d==0) ans = n;
  else if (d==1) ans = n*100;
  else if (d==2) ans = n*100*100;
  if (n==100) ans += pow(100,d);
  cout << ans << endl;
  return 0;
}