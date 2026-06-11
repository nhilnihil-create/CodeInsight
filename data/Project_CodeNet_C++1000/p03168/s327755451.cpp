#include<bits/stdc++.h>
using namespace std;
long double coins[3005];
int n;
long double dp[3005][3005][3];

int main(){
   
    cin >> n;
    for(int i=1;i<=n;i++) cin >> coins[i];
    
    
    for(int i=n;i>=0;i--){
        for(int j=n;j>=0;j--){
            for(int k=1;k>=0;k--){
                if(i==n){
                    if(j<=(n/2)) dp[i][j][k]=0;
                    else if(k==1) dp[i][j][k]=coins[i];
                    else dp[i][j][k]=1-coins[i];
                }
                
                else{
                    long double t1,t2;
                    if(i==0){
                        t1=dp[i+1][j][0];
                        t2=dp[i+1][j+1][1];
                    }
                    else if(k==1){
                        t1=dp[i+1][j][0]*coins[i];
                        t2=dp[i+1][j+1][1]*coins[i];
                    }
                    else{
                        t1=dp[i+1][j][0]*(1-coins[i]);
                        t2=dp[i+1][j+1][1]*(1-coins[i]);
                    }
                    dp[i][j][k]=t1+t2;
                }
            }
        }
    }
    printf("%0.12Lf\n",dp[0][0][0]);
}