#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
using namespace std;
const ll mod=1e9+7;
tuple<ll,ll,ll>x[110000];
main(){
  ll n,ans=0,t1,t2;
  cin>>n;
  rep(i,0,n){cin>>t1>>t2;x[i]=make_tuple(t1+t2,t1,t2);}
  sort(x,x+n,greater<tuple<ll,ll,ll>>());
  rep(i,0,n){
    if(i%2==0)ans+=get<0>(x[i]);
    ans-=get<2>(x[i]);
  }
  cout<<ans;
}