#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59


int main(){
  ll i,j;
  ll n;
  cin>>n;
  ll a[n],b[n];
  for(i=0;i<n;i++) cin>>a[i];
  for(i=0;i<n;i++) cin>>b[i];
  
  ll c[n];
  ll ans=0;
  for(i=0;i<29;i++){
    for(j=0;j<n;j++){
      c[j]=b[j]&((1<<(i+1))-1);
    }
    sort(c,c+n);
    ll p;
    ll q=0;
    for(j=0;j<n;j++){
      p=a[j]&((1<<(i+1))-1);
      q+=upper_bound(c,c+n,(1<<(i+2))-1-p)-lower_bound(c,c+n,(1<<(i+1))+(1<<i)-p);
      q+=upper_bound(c,c+n,(1<<(i+1))-1-p)-lower_bound(c,c+n,(1<<i)-p);
      q%=2;
    }
    if(q&1) ans+=(1<<i);
  }
  cout<<ans<<endl;


  return 0;
}