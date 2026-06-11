#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=998244353;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
int mpow(int a,int b){
    int ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
const int FACTSIZE=1111111;
int fact[FACTSIZE];
int factinv[FACTSIZE];
class FactInit{
public:
    FactInit(){
        fact[0]=1;
        for(int i=1;i<FACTSIZE;i++)fact[i]=fact[i-1]*i%mod;
        factinv[FACTSIZE-1]=mpow(fact[FACTSIZE-1],mod-2);
        for(int i=FACTSIZE-2;i>=0;i--)factinv[i]=factinv[i+1]*(i+1)%mod;
    }
}factInit;

int binomial(int n,int k){
    return fact[n]*factinv[k]%mod*factinv[n-k]%mod;
}

signed main(){
    int N,A,B,K;
    cin>>N>>A>>B>>K;
    int ans=0;
    for(int i=0;i<=N;i++){
        if(i*A>K||(K-i*A)%B||(K-i*A)/B>N)continue;
        add(ans,binomial(N,i)*binomial(N,(K-i*A)/B)%mod);
    }
    cout<<ans<<endl;
    return 0;
}