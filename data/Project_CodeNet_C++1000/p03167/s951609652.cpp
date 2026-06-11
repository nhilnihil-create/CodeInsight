#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define P pair<int,int>
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)

int main(void){
    int h,w;
    cin >> h >> w;
    char c[h][w];
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++)cin >> c[i][j];
    }
    
    ll mod = 1e9+7,dp[h+1][w+1];
    for(int i = 0;i <= h;i++){
        for(int j = 0;j <= w;j++)dp[i][j] = 0;
    }
    
    dp[0][0] = 1;
    
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(c[i][j] == '#')continue;
            
            if(i > 0)dp[i][j] += dp[i-1][j];
            if(j > 0)dp[i][j] += dp[i][j-1];
            
            dp[i][j] %= mod;
        }
    }
    
    cout << dp[h-1][w-1] << endl;
}