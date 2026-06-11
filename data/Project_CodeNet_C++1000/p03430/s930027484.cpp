#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n = s.size();
    int dp[n+1][n+1][k+1];
    int ans = 0;
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            for(int c=0; c<k+1; c++){
                dp[i][j][c] = 0;
            }
        }
    }


    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            for(int c=0; c<k+1; c++){
                if(i<n)
                    dp[i+1][j][c] = max(dp[i][j][c],dp[i+1][j][c]);
                if(j<n)
                    dp[i][j+1][c] = max(dp[i][j][c],dp[i][j+1][c]);
                if(i<n &&j<n && i+j<n){
                    if(s[i] == s[n-1-j]){
                         dp[i+1][j+1][c] = max(dp[i+1][j+1][c], dp[i][j][c]+1);
                         if(i+j==n-1)
                            ans = max(ans, 2*dp[i+1][j+1][c]-1);
                         else
                            ans = max(ans,2*dp[i+1][j+1][c]);
                    }
                    else if(c<k){
                        dp[i+1][j+1][c+1] = max(dp[i+1][j+1][c+1], dp[i][j][c]+1);
                         if(i+j==n-1)
                            ans = max(ans, 2*dp[i+1][j+1][c+1]-1);
                         else
                            ans = max(ans,2*dp[i+1][j+1][c+1]);
                    }
                }


            }
        }
    }
    cout<<ans<<endl;



    return 0;
}
