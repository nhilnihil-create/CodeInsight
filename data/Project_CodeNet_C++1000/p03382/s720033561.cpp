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
ll a[110000];
int main(){
  ll n,cnt=-1,ans=0,st=1100000000;
  cin>>n;
  rep(i,0,n)cin>>a[i];
  sort(a,a+n);
  ll x=a[n-1];
  rep(i,0,n-1){
    if(st>abs(x-a[i]*2)){
      st=abs(x-a[i]*2);
      cnt=i;
      }
  }
  cout<<x<<" "<<a[cnt];
}
