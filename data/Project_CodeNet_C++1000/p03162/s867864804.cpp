#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &dp, vector<vector<int>> &p, int i, int last){
    if(i == p.size()){
        return 0;
    }
    if(dp[i][last] != -1){
        return dp[i][last];
    }
    int ans = INT_MIN;
    for(int j = 0; j < 3; ++j){
        if(j != last){
            ans = max(ans, p[i][j] + solve(dp, p, i+1, j));
        }
    }
    return dp[i][last] = ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> p(n+1, vector<int>(3, 0));
    vector<vector<int>> dp(n+1, vector<int> (3, -1));
    for(int i = 1; i <= n; ++i){
        cin>>p[i][0];
        cin>>p[i][1];
        cin>>p[i][2];
    }
    int ans = max({p[1][0]+solve(dp, p, 2, 0), p[1][1]+solve(dp, p, 2, 1), p[1][2]+solve(dp, p, 2, 2)});
    cout<<ans;
    return 0;
}
