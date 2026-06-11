#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000000000 + 7;
int main() {
    ll n, i, j, k;
    cin >> n;
    vector<ll> c(n);
    vector<vector<ll>> place(2 * 100000 + 20);
    for(i = 0; i < n; i++) {
        cin >> c[i];
        place[c[i]].push_back(i);
    }
    vector<ll> dp(n, 0);
    dp[0] = 1;
    for(i = 1; i < n;i++){
        dp[i] = (dp[i]+dp[i - 1])%MOD;
        int it = lower_bound(place[c[i]].begin(), place[c[i]].end(), i) - place[c[i]].begin();
        if(it == 0) continue;
        it--;
        if(i-place[c[i]][it]>1){
            dp[i] = (dp[i] + dp[place[c[i]][it]]) % MOD;
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}