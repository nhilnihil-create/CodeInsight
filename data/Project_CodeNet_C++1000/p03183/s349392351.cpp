#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;

int constexpr N = 1005, W = 20005;
int n;
tuple<int, int, int> sw[N];
ll dp[W];
ll constexpr INF = numeric_limits<ll>::max() / 1000;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> get<1>(sw[i]) >> get<0>(sw[i]) >> get<2>(sw[i]);
        get<0>(sw[i]) += get<1>(sw[i]); // s += w
    }
    sort(sw + 1, sw + n + 1);
    fill(dp, dp + W, -INF);
    dp[0] = 0;

    for(int i = 1; i <= n; ++i) {
        int s = get<0>(sw[i]);
        int w = get<1>(sw[i]);
        int v = get<2>(sw[i]);
        for(int j = W - 1; j >= 0; --j) {
            if(j + w < W && dp[j] + v > dp[j + w] && j + w <= s) {
                dp[j + w] = dp[j] + v;
            }
        }
    }
    cout << *max_element(dp, dp + W) << '\n';
}