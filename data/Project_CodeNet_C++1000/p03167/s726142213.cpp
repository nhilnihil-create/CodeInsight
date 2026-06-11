#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
int main() {
    int n, m;
    cin>>n>>m;
    char grid[n][m];
    long long int dp[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            dp[i][j] = 0;
        }
    }
    
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(grid[i][j]!='#'){
                if(i==n-1 && j==m-1){
                    dp[i][j] = 1;
                }
                else if(j!=m-1 && i==n-1){
                    dp[i][j] = dp[i][j+1];
                }
                else if(i!=n-1 && j==m-1){
                    dp[i][j] = dp[i+1][j];
                }
                else{
                    dp[i][j] = ((dp[i+1][j] % mod) + (dp[i][j+1] % mod)) % mod;
                }
            }
            else
                dp[i][j] = 0;
            
        }
    }
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<dp[0][0];
}