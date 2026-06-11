#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)

const int INF = 1 << 29;

int main(void){
    int n;
    cin >> n;
    vector<ll> v;
    v.push_back(1);
    for(int i = 9;i <= n;i *= 9)v.push_back(i);
    for(int i = 6;i <= n;i *= 6)v.push_back(i);
    
    vector<vector<ll>> dp(v.size()+1,vector<ll>(n+1,INF));
    dp[0][0] = 0;
    
    for(int i = 0;i < v.size();i++){
        for(int j = 0;j <= n;j++){
            if(j >= v[i])dp[i+1][j] = min(dp[i][j],dp[i+1][j-v[i]]+1);
            else dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
        }
    }
    
    cout << dp[v.size()][n] << endl;
}