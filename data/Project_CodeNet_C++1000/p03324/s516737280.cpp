#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int d,n; cin>>d>>n;
  int ans = n*pow(100,d);
  if (n==100) ans += pow(100,d);
  cout << ans << endl;
  return 0;
}