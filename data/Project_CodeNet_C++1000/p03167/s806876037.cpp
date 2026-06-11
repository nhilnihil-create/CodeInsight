#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
 
void solve(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> arr(h,vector<char>(w,0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            cin>>arr[i][j];
    }
    vector<vector<int>> dp(h,vector<int>(w,0));
    dp[0][0]=1;
    for(int i=1;i<h;i++)
        dp[i][0]=(arr[i-1][0]=='#')?0:dp[i-1][0];
    for(int i=1;i<w;i++)
        dp[0][i]=(arr[0][i-1]=='#')?0:dp[0][i-1];
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            int x=(arr[i-1][j]=='#')?0:dp[i-1][j];
            int y=(arr[i][j-1]=='#')?0:dp[i][j-1];
            dp[i][j]=(x+y)%mod;
        }
    }
    cout<<dp[h-1][w-1];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve(); cout<<endl;
    return 0;
}