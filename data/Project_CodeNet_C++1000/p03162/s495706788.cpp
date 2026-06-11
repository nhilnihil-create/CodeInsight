#include <iostream>

using namespace std;

const int MAX=100000+3;
int N, ns[MAX][3];
int dp[MAX][3];
int main(){

    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d%d%d",&ns[i][0],&ns[i][1],&ns[i][2]);


    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            if(j==0) dp[i][j]=ns[i-1][0]+max(dp[i-1][1], dp[i-1][2]);
            if(j==1) dp[i][j]=ns[i-1][1]+max(dp[i-1][0], dp[i-1][2]);
            if(j==2) dp[i][j]=ns[i-1][2]+max(dp[i-1][0], dp[i-1][1]);
        }
    }
    int ans=0;
    for(int i=0;i<3;i++) ans=max(ans, dp[N][i]);
    cout << ans << endl;


    return 0;
}
