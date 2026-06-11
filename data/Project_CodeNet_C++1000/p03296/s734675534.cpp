#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int Data[105],dp[105][2];
int N;

int main(){
    scanf("%d",&N);
    for(register int i=1;i<=N;++i)
        scanf("%d",&Data[i]);
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    dp[1][1]=1;
    for(register int i=2;i<=N;++i){
        if(Data[i]==Data[i-1]) dp[i][0]=dp[i-1][1];
        else dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
    }
    printf("%d\n",min(dp[N][0],dp[N][1]));
    //system("pause");
    return 0;
}