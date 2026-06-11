//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

void inverse(ll n,vector<ll> &inv){
    //要素数:n+1 (0~n)
    inv[0]=1;
    inv[1]=1;
    for(ll i=2;i<=n;i++){
        inv[i]=(mod-inv[mod%i]*(mod/i))%mod;
    }
}

void inverse_u(ll n,vector<ll> &inv){
    //要素数:n+1 (0~n)
    for(ll i=2;i<=n;i++){
        inv[i]=(inv[i]*inv[i-1])%mod;
    }
}

void factorial(ll n,vector<ll> &fac){
    //要素数:n+1 (0~n)
    fac[1]=1;
    for(ll i=2;i<=n;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}

ll nCr(ll n,ll r,vector<ll> &inv,vector<ll> &fac){
    return fac[n]*inv[r]%mod*inv[n-r]%mod;
}

int main(){
    ll n,a,b,k,ans=0; cin>>n>>a>>b>>k;
    vector<ll> inv(n+1,0),fac(n+1,0);
    inverse(n,inv); inverse_u(n,inv);
    factorial(n,fac);
    for(ll i=0;i<=n;i++){
        ll l=k-i*a;
        if(l%b!=0) continue;
        l/=b;
        if(l<0 || l>n) continue;
        ans=(ans+nCr(n,i,inv,fac)*nCr(n,l,inv,fac)%mod)%mod;
    }
    cout<<(ans+mod)%mod<<endl;
}