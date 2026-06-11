#include<bits/stdc++.h>
#define int int64_t
using namespace std;

int a[16][16], INF = 1e17;
vector<int> cost((1 << 16));

int calc(int x) {
    int cost = 0;
    for(int i = 0; i <= 15; i++) {
        for(int j = i+1; j <= 15; j++) {
            if((x & (1 << i)) && (x & (1 << j))) {
                cost += a[i][j];
            }
        }
    }
    return cost;
}

vector<int> dp((1 << 16) , -INF);
int solve(int mask) {
    if(mask == 0) return 0;
    else if(dp[mask] != -INF) return dp[mask];
    for(int sub = mask; sub > 0; sub = (sub-1)&mask) {
        dp[mask] = max(dp[mask] , cost[sub] + solve((mask^sub)));
    }
    return dp[mask];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    for(int i = 0; i < (1 << n); i++) cost[i] = calc(i);
    cout << solve((1 << n)-1) << "\n";

    return 0;
}

