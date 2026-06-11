#include <iostream>
using namespace std;
typedef long long LL;
const int N=5022;
LL dp[N][N];
int n,a,b,x[N],pos[N];
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]), pos[x[i]]=i;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=1e18;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        LL mn=dp[i-1][0];
        for(int j=0;j<=n+1;j++){
            mn=min(mn,dp[i-1][j]);

            if(j==pos[i]) dp[i][j]=mn;
            else if(j<pos[i]) dp[i][j]=mn+min(1LL*b,1LL*a*(pos[i]-j));
            else dp[i][j]=mn+min(1LL*a,1LL*b*(j-pos[i]));
    
            //printf("dp[%d][%d]=%lld\n", i,j,dp[i][j]);
        }
    }
    LL ans=1e18;
    for(int i=0;i<=n+1;i++)ans=min(ans,dp[n][i]);
    cout<<ans<<endl;
}