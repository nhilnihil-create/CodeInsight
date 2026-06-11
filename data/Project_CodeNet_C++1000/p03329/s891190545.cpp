#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    int n; cin >> n;

    V<int> dp(n + 1, n);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int p6 = 1; p6 <= i; p6 *= 6){
            dp[i] = min(dp[i], dp[i - p6] + 1);
        }
        for(int p9 = 1; p9 <= i; p9 *= 9){
            dp[i] = min(dp[i], dp[i - p9] + 1);
        }
    }

    cout << dp[n] << endl;

}
