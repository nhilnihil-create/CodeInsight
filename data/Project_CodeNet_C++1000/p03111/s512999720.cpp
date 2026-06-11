#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,A,B,C;
  cin >> n >> A >> B >> C;
  vec l(n);
  for(ll i=0;i<n;i++) cin >> l[i];
  ll ans=inf;
  for(ll i=0;i<(1<<n*2);i++) {
    ll a=0,b=0,c=0;
    ll bit=i;
    ll tans=0;
    for(ll j=0;j<n;j++) {
      ll check=bit%4;
      bit/=4;
      if(check==1) {
        if(a) tans+=10;
        a+=l[j];
      }
      if(check==2) {
        if(b)tans+=10;
        b+=l[j];
      }
      if(check==3) {
        if(c) tans+=10;
        c+=l[j];
      }
    }
    if(a*b*c==0) continue;
    tans+=abs(A-a)+abs(B-b)+abs(C-c);
    ans=min(ans,tans);
  }
  cout << ans << endl;
}