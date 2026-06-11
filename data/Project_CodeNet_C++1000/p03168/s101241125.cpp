#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    // dp[heads]
    // if we had i tosses, then tails=i-heads
    vector<double> dp(n + 1);
    // dp[i] - p-bility that there are i heads so far
    dp[0] = 1;
    for(int coin = 0; coin < n; ++coin) {
        double p_heads;
    
        cin >> p_heads;
        for(int i = coin + 1; i >= 0; --i) {
            dp[i] = (i == 0 ? 0 : dp[i-1] * p_heads) + dp[i] * (1 - p_heads);
        }
    }
    double answer = 0;
    for(int heads = 0; heads <= n; ++heads)
     {
        int tails = n - heads;
        if(heads > tails) 
            answer += dp[heads];
        
    }
   cout<< setprecision(16) << answer;
}