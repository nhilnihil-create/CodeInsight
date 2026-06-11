#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>v(h,vector<char>(w));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>v[i][j];
        }
    }
    vector<vector<int>>dp(h,vector<int>(w,0));    
    dp[0][0]=1;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(i>=1&&v[i-1][j]=='.'){
                dp[i][j]+=dp[i-1][j];
                dp[i][j]%=mod;
            }
            if(j>=1&&v[i][j-1]=='.'){
                dp[i][j]+=dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[h-1][w-1];
}