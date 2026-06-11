#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXN=1e5+10;
    static const ll MOD=1e9+7;
    char S[MAXN];
    ll preA[MAXN],sufC[MAXN];
    ll preQ[MAXN],sufQ[MAXN];
    ll pow3[MAXN];
    ll pow(ll b,ll t){
        if(t==0)return 1;
        ll tmp=pow(b,t/2);
        tmp=(tmp*tmp)%MOD;
        if(t%2)tmp=tmp*b%MOD;
        return tmp%MOD;
    }
    void solve(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>S+1;
        int n=strlen(S+1);
        pow3[0]=1;
        for(int u=1;u<=n;u++){
            pow3[u]=pow3[u-1]*3%MOD;
        }
        for(int u=1;u<=n;u++){
            if(S[u]=='A')preA[u]=preA[u-1]+1;
            else preA[u]=preA[u-1];
            if(S[u]=='?')preQ[u]=preQ[u-1]+1;
            else preQ[u]=preQ[u-1];
        }
        for(int u=n;u>=1;u--){
            if(S[u]=='C')sufC[u]=sufC[u+1]+1;
            else sufC[u]=sufC[u+1];
            if(S[u]=='?')sufQ[u]=sufQ[u+1]+1;
            else sufQ[u]=sufQ[u+1];
        }
        ll ans=0;
        for(int u=2;u<n;u++){
            if(S[u]=='?'||S[u]=='B'){
                ll t[4]={0};
                t[0]=preA[u-1]*sufC[u+1]%MOD*pow3[preQ[u-1]+sufQ[u+1]]%MOD;
                t[1]=preA[u-1]*sufQ[u+1]%MOD*pow3[preQ[u-1]+sufQ[u+1]-1]%MOD;
                t[2]=preQ[u-1]*sufC[u+1]%MOD*pow3[preQ[u-1]+sufQ[u+1]-1]%MOD;
                t[3]=preQ[u-1]*sufQ[u+1]%MOD*pow3[preQ[u-1]+sufQ[u+1]-2]%MOD;
                for(int v=0;v<4;v++)ans=(ans+t[v])%MOD;
            }
        }
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}