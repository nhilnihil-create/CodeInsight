#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+5,mod = 998244353;
ll fct[N],inv[N],invfct[N];
void init(){
    fct[0]=fct[1]=1;
	inv[1]=1;
	invfct[0]=invfct[1]=1;
	for(ll i=2;i<N;i++){
		fct[i]=i*fct[i-1]%mod;
		inv[i]=ll(mod-inv[mod%i])*(mod/i)%mod;
		invfct[i]=ll(inv[i])*invfct[i-1]%mod;
	}
}
inline ll ncr(ll n,ll r){
    if(n-r<0 || n<0 || r<0)return 0;
    ll ans = fct[n]*invfct[n-r];
    ans%=mod;
    ans = ans*invfct[r];
    ans%=mod;
    return ans;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    ll n,ans=0,A,B,K;cin>>n>>A>>B>>K;
    for(ll a=0;a<=n&&K-A*a>=0;a++){
        ll val = K - A*a;
        if(val%B || val/B>n)continue;
        ans = ans + (ncr(n,a)*ncr(n,val/B))%mod;
        ans%=mod;
    }
    cout<<ans;
}