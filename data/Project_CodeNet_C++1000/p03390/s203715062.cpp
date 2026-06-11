#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
ll ma(ll a,ll k){
    if(a+1<=k){
	ll sum=a+1+k;
	ll x=sum/2,y=sum-x;
	return x*y;
    }
    return k*(a+1);
}
void solve(){
    ll a,b; cin>>a>>b;
    if(a>b)swap(a,b);
    ll l=0,r=1e10,mid;
    while(l<r-1){
	mid=(l+r)>>1;
	if(ma(a,mid)<a*b)l=mid;
	else r=mid;
    }
    cout<<a+l-1<<endl;
}
int main(){
  ll q; cin>>q;
  while(q--)solve();
  return 0;
}
