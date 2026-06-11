//2019.5.15 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f3f3f3f
#define eps 1e-10
#define RG register
inline int read() {
    res s=0,ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s;
}
inline LL Read() {
    RG LL s=0;
    res ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s;
}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=5e3+10;
namespace MAIN {
    int n,A,B,pos[N];
    LL dp[2][N],ans=inf;
    inline void MAIN(){
        n=read(),A=read(),B=read();
        for(res i=1;i<=n;i++)pos[read()]=i,dp[0][i]=inf;
        res cur=0;
        for(res i=1;i<=n;i++){
            for(res j=0;j<=i;j++)dp[cur^1][j]=inf;
            for(res j=0;j<i;j++){
                RG LL DP=dp[cur][j];
                if(DP!=inf){
                    if(pos[i]>pos[j])dp[cur^1][i]=min(dp[cur^1][i],DP),dp[cur^1][j]=min(dp[cur^1][j],DP+B);
                    else dp[cur^1][j]=min(dp[cur^1][j],DP+A);
                }
            }
            cur^=1;
        }
        for(res i=1;i<=n;i++)ans=min(ans,dp[cur][i]);
        printf("%lld\n",ans);
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("graph.in","r",stdin);
//    freopen("graph.out","w",stdout);
    MAIN::MAIN();
    return 0;
}