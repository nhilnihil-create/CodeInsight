#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

constexpr int INF = 100000000;

int main() {
    int n;
    cin >> n;
    vector<int> dp(100010,INF);
    dp[0] = 0;
    for(int i = 1; i < 100010; i++) {
        int power = 1;
        while(power <= i) {
            dp[i] = min(dp[i],dp[i-power]+1);
            power *= 6;
        }
        power = 1;
        while(power <= i) {
            dp[i] = min(dp[i],dp[i-power]+1);
            power *= 9;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}