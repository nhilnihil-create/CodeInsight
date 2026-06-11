#include<bits/stdc++.h>
using namespace std;

int dp[100005][3];

int main(){
    
    int n; 
    cin>>n;
    
    int v[n][3];
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            cin>>v[i][j];
    }
    
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    
    for(int i=1; i<n; i++){
        
        for(int j=0; j<3; j++){
            int x = INT_MIN;
            for(int k=0; k<3; k++){
            if(j!=k){
            dp[i][j] = max((dp[i-1][k])+v[i][j],x);
            x = dp[i][j];
            }
            }
        }
        
    }
 //   cout<<dp[n-1][0]<<" "<<dp[n-1][1]<<" "<<dp[n-1][2]<<endl;
    
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
    
}