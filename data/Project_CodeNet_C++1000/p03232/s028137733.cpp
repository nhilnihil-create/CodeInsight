#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100005,INF=1<<30;

ll inv[MAX],fac[MAX],finv[MAX];

void make(){
    
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    
    for(int i=2;i<MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll)i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
    
}

ll comb(ll a,ll b){
    if(a<b) return 0;
    return fac[a]*(finv[b]*finv[a-b]%mod)%mod;
}

int main(){
    
    make();
    
    int N;cin>>N;
    vector<ll> A(N),B(N);
    
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    for(int i=0;i<N;i++){
        B[i]=fac[i]*finv[i+1]%mod;
        if(i) B[i]=(B[i]+B[i-1])%mod;
    }
    
    ll ans=0;
    
    for(int i=0;i<N;i++){
        ans+=A[i]*((B[i]+B[N-1-i]+mod-1)%mod)%mod;
        ans%=mod;
    }
    
    cout<<ans*fac[N]%mod<<endl;
    
}

