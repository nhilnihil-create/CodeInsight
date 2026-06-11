#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<iomanip>
#include<bitset>
#define mod 1000000007
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

ll n,m;
ll x[200010],rui[200010];
int main(){
    cin>>n>>m;
    rui[0]=0;
    for(int i=0;i<n;i++){
	cin>>x[i];
    }
    sort(x,x+n,greater<ll>());
    for(int i=0;i<n;i++){
	rui[i+1]=rui[i]+x[i];
    }
    ll ans=1e17;
    for(ll k=1;k<=n;k++){
	ll res=m*(n+k);
	for(ll p=0;p*k<n;p++){
	    ll l=p*k,r=(p+1)*k-1;
	    chmin(r,n-1);
	    ll kei=2*p+3;
	    if(p==0)kei=5;
	    res+=kei*(rui[r+1]-rui[l]);
	    chmin(res,(ll)1e17);
	}
	chmin(ans,res);
    }
    cout<<ans<<endl;
}

