#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll x = 1e9 + 7;
ll mat[1000][1000];

ll paths(int m, int n, vector<vector<char>>& v){

    ll dp[m][n] ;
    dp[0][0] = 1;
    for(int i = 1; i < n; i++) (v[0][i] == '.') ? dp[0][i] = dp[0][i-1] : dp[0][i] = 0;
    for(int i = 1; i < m; i++) (v[i][0] == '.') ? dp[i][0] = dp[i-1][0] : dp[i][0] = 0;
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(v[i][j] == '.') dp[i][j] = dp[i-1][j] + dp[i][j-1];
            else dp[i][j] = 0;
            dp[i][j] %= x;
        }
        
    }
    return dp[m-1][n-1] % x;
    
}

int main(){
    int m,n ; cin >> m >> n;
    vector<vector<char>> v(m, vector<char>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    
    
    cout << paths(m,n,v) ;
    return 0;
}