#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char arra[n+5][m+5];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arra[i][j];
        }
    }
    int dp[n+5][m+5];
    memset(dp,0,sizeof(dp));
    
    dp[0][0]=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0 && j!=0) {
                if(arra[i][j]=='#') {
                    dp[i][j]=0;

                }
                else {
                    dp[i][j]=dp[i][j-1];
                }
            }
            else if(j==0 && i!=0) {

                if(arra[i][j]=='#') {
                    dp[i][j]=0;

                }
                else {
                    dp[i][j]=dp[i-1][j];
                }

            }
            else  if(i>0 && j>0){
                if(arra[i][j]=='#') {
                    dp[i][j]=0;

                }
                else {
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;

                }
            }


        }
    }
    cout<<dp[n-1][m-1]<<endl;


}
