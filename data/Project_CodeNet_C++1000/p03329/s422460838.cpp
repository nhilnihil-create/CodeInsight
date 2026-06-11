#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD =  1000000007;
const ll INF = 1LL << 60;


int main() {
    int n; cin >> n;

    V<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++) dp[i] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 6; j <= i; j*= 6){
            dp[i] = min(dp[i - j] + 1, dp[i]);
        }
        for(int j = 9; j <= i; j*= 9){
            dp[i] = min(dp[i - j] + 1, dp[i]);
        }
    }
    cout << dp[n] << endl;

    return 0;
}
