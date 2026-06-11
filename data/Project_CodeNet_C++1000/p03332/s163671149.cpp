#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<iomanip>
#include<bitset>
#define mod 998244353
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mad(a,b) a=(a+b)%mod
#define mul(a,b) a=a*b%mod

#define N 600010
ll fac[N],ivf[N],inv[N];
ll C(ll n,ll k){
    if(n<k)return 0;
    if(k<0)return 0;
    return fac[n]*ivf[k]%mod*ivf[n-k]%mod;
}
int main(){
    fac[0]=ivf[0]=inv[1]=1;
    for(ll i=1;i<N;i++){
	if(i>1)inv[i]=(mod-(mod/i*inv[mod%i]%mod))%mod;
	fac[i]=fac[i-1]*i%mod;
	ivf[i]=ivf[i-1]*inv[i]%mod;
    }//cout<<C(5,2)<<endl;
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    ll ans=0;
    for(int i=0;i<=n;i++){
	ll rem=k-i*a;
	if(rem%b==0){
	    mad(ans,C(n,i)*C(n,rem/b));
	}
    }
    cout<<ans<<endl;
}


