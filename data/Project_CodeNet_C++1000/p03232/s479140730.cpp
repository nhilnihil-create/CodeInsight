#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

const long long MAX=510000;
//階乗,逆元,逆元の階乗
long long fac[MAX],inv[MAX],finv[MAX];
//テーブルを作る前処理
void COMinit() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}

int main(){
    long long n; cin>>n;
    long long a[n]; rep(i,n) cin>>a[i];
    COMinit();
    long long iinv[n]; iinv[0]=1;
    for(int i=1;i<n;i++){
        iinv[i]=(inv[i+1]+iinv[i-1])%MOD;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i]*fac[n]%MOD*(iinv[i]+iinv[n-1-i]-1)%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}
