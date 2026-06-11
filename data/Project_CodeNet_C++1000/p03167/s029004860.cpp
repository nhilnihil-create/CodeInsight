#include <iostream>

using namespace std;
const int MOD=1e9+7;
int n, m;
char ns[1000+3][1000+3];
int dp[1000+3][1000+3];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s", ns[i]);
    }


    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!i&&!j) continue;
            if(ns[i][j]=='#') continue;
            if(i) dp[i][j] += dp[i-1][j]%MOD;
            if(j) dp[i][j] += dp[i][j-1]%MOD;
            dp[i][j]%=MOD;
        }
    }

    printf("%d\n", dp[n-1][m-1]);



    return 0;
}
