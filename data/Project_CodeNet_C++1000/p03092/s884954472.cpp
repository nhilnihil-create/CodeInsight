#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const int MAX=5345;
const LL llinf=1ll<<60;
int n,c[MAX],ub[MAX][MAX];
LL a,b,dp[MAX][MAX];
int main(){
    scanf("%d%lld%lld",&n,&b,&a);
    for(int i=1;i<=n;++i)scanf("%d",&c[i]);
    for(int i=0;i<=n+1;++i)ub[0][i]=inf;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            ub[i][j]=ub[i-1][j];
            if(c[i]>j&&c[i]<ub[i][j])ub[i][j]=c[i];
        }
    }
    for(int i=1;i<=n+1;++i){
        if(i<=c[1])dp[1][i]=b;
        else dp[1][i]=0;
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            if(j<=c[i]){
                dp[i][j]=dp[i-1][j]+b;
            }
            else if(j>c[i]&&j<=ub[i-1][c[i]]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=min(dp[i-1][j]+a,dp[i-1][ub[i-1][c[i]]]);
            }
        }
    }
    LL sx5=llinf;
    /*for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            printf("%d %d:%lld\n",i,j,dp[i][j]);
        }
    }*/
    for(int i=1;i<=n+1;++i){
        sx5=min(sx5,dp[n][i]);
    }
    printf("%lld\n",sx5);
    return 0;
}