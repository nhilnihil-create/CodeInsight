#include<bits/stdc++.h>
using namespace std;
int main(){
    int m = 1000000007;
    int r,c;
    cin>>r>>c;
    
    vector<vector<char>> v (r,vector<char>(c,'.'));
    vector<vector<long long>> dp(r,vector<long long>(c,0));
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>v[i][j];
        }
    }
    

    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            
            if(i==0 && j==0) dp[i][j]=1;
            
            
            else if(v[i][j]!='#'){
                
            if(i>0 && j>0){
                if(v[i][j-1]!='#' && v[i-1][j]!='#'){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
                else if(v[i][j-1]!='#'){
                    dp[i][j] = dp[i][j-1];
                }
                else if(v[i-1][j]!='#'){
                    dp[i][j] = dp[i-1][j];
                }
                
            }else if(i>0){
                if(v[i-1][j]!='#'){
                    dp[i][j] = dp[i-1][j];
                }
                
            } 
            else if(j>0){
                if(v[i][j-1]!='#'){
                    dp[i][j] = dp[i][j-1];
                }
                
            } 
            
            
            
        }
        dp[i][j] = dp[i][j]%m;
        }
        
    }
    
    cout<<dp[r-1][c-1]<<endl;
    
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout<<dp[i][j];
    //     }
    //     cout<<endl;
    // }
    
    
    
    
    
}