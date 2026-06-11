#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;

    vector<int> c(n);
    vector<vector<int>> color(1e6);
    for(int i=0; i<n; i++){
        cin >> c[i];
        color[c[i]].push_back(i);
    }
    
    vector<long long int> dp(n+1);
    dp[0] = 1;
    for(int i=0; i<n; i++){
        dp[i+1] += dp[i];

        int j = lower_bound(color[c[i]].begin(), color[c[i]].end(), i) - color[c[i]].begin();
        if(j >= 1 && color[c[i]][j-1] < i-1) dp[i+1] += dp[color[c[i]][j-1] + 1];

        dp[i+1] %= MOD;
    }
    cout << dp[n] << endl;
    return 0;
}