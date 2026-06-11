#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> prev(200000, -1), dp(N + 1);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        int C;
        cin >> C;
        C--;
        (dp[i + 1] += dp[i]) %= MOD;
        if ((i > 0 && prev[C] == i - 1) || prev[C] == -1) {
            prev[C] = i;
            continue;
        }
        (dp[i + 1] += dp[prev[C] + 1]) %= MOD;
        prev[C] = i;
    }

    cout << dp[N] << endl;
    return 0;
}
