#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=100010;
const ll mod=1e9+7;

int main(){  
  int k;
  cin >> k;
  vector<ll> a(k);
  rep(i,k) cin >> a[i];
  reverse(a.begin(),a.end());

  ll cnt = 2;
  ll ans = 2;
  if(a[0]!=2){ cout << -1 << endl; return 0; }
  rep(i,k){
    if(cnt%a[i]!=0 && cnt/a[i]==ans/a[i]){
      cout << -1 << endl; return 0;
    }
    cnt = ((cnt-1)/a[i])*a[i]+a[i];
    ans = (ans/a[i])*a[i] + a[i]-1;
  }
  cout << cnt << " " << ans << endl;
  return 0;
}