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

const int mod=1000000007;
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


int binom(int n,int k){
    return fact[n]*factinv[n-k]%mod*factinv[k]%mod;
}

int perm(int n,int k){
    return fact[n]*factinv[n-k]%mod;
}

int N;
int A[111111];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];

    vint S(N+1);
    rep(i,N)S[i+1]=S[i]+mpow(i+1,mod-2);

    int ans=0;
    rep(i,N){
        int tmp=(S[i+1]+S[N-i]+mod-1)%mod;
        add(ans,tmp*A[i]%mod);
    }
    cout<<ans*fact[N]%mod<<endl;
    return 0;
}