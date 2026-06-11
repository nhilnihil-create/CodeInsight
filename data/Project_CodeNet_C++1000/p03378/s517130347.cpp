#include <bits/stdc++.h>
using namespace std;  

int main() {
    int n, m, x, a, dp[101] = {};
    cin >> n >> m >> x;
    for ( int i = 0; i < m; i++ ) {
        cin >> a;
        dp[a] ++;
    }
    
    for ( int i = 0; i < n; i++ ) {
        dp[i+1] += dp[i];
    }
    
    cout << min(dp[n]-dp[x], dp[x]) << endl;
    
    return (0);
}
