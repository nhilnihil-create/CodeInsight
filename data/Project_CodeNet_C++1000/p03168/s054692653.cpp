#include <bits/stdc++.h>
using namespace std;

double solve(vector<vector<double>> &dp, vector<double> &p, int i, int h){
        if(h < 0){
        return 0;
    }
    if(i<h){
        return 0;
    }

    if(i==0){
        return 1;
    }
    if(dp[i][h] != -1){
        return dp[i][h];
    }
    dp[i][h] = p[i]*solve(dp, p, i-1, h-1) + (1-p[i])*solve(dp, p, i-1, h);
    // cout<<temp<<endl;
    return dp[i][h];
}

int main(){
    int n;
    cin>>n;
    vector<double> p(n+1, 0.0);
    for(int i = 1; i <= n;++i){
        scanf("%lf", &p[i]);
    }
    double ans = 0;
    vector<vector<double>> dp(n+1, vector<double> (n+1, -1));
    // solve(p, n, n/2 + 1);
    for(int i = n/2+1; i <= n; ++i){
        // cout<<solve(p, n, i)<<endl;
        ans += solve(dp, p, n, i);
    }
    printf("%0.10lf", ans);
    return 0;
}
