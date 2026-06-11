#include <bits/stdc++.h>
#define pb push_back
#define Int long long
using namespace std;

const int MAXN=500005;
const int NAX=1005;
const long long  MOD=(long long)(998244353);

Int N,M,K;
Int X,Y,Z;
Int H,W;
Int perform(Int x){
    return (x*(x+1))/2LL;
}
vector<Int> A;
vector<int> adj[MAXN];
using D=long double;

bool inRange(Int a,Int b){
    return a*b<=0;
}

long long C[NAX][NAX];
const D pi=3.14159265359;


long long ModExpo(long long x,unsigned long long y,long long M){
    Int ans=1;
    ans=(long long)ans;
    
    while(y>0){
        if(y&1) ans=((ans%M)*(x%M))%M;
        y>>=1LL;
        x=((x%M)*(x%M))%M;
    }
    return ans%M;
}
long long fac[MAXN];
void fillFac(){
    fac[0]=1;
    for(int i=1;i<MAXN;++i){
        fac[i]=((fac[i-1]%MOD)*(i%MOD))%MOD;
    }
}

long long ModInv(long long x){
    return ModExpo(x,MOD-2,MOD);
}

long long FermatLast(long long n,long long r){
    if(r>n) return 0;
    if(!r) return 1;
    return (fac[n] * ModInv(fac[r]) % MOD * ModInv(fac[n - r]) % MOD) % MOD;
}

Int performMod(Int x){
    Int y=((x%MOD)*((x+1)%MOD))%MOD;
    return (y*ModInv(2))%MOD;
}

Int madd(Int x,Int y){
    return (x+y)%MOD;
}

Int mmul(Int x,Int y){
    return ((x%MOD)*(y%MOD))%MOD;
}

int main()
{
    fillFac();
    Int ans=0;
    cin>>N>>X>>Y>>K;
        for(Int i=0;i<=N;++i){
            Int rem=K-X*i;
            if(rem<0||rem%Y) continue;
            Int newB=rem/Y;
            if(newB>N) continue;
            ans=madd(ans,mmul(FermatLast(N,i),FermatLast(N,newB)));
        }
        cout<<ans<<"\n";
    
}
