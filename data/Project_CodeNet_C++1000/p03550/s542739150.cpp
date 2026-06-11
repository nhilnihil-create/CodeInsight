#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pdd = pair<double, double>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    vector<vector<int>> dp(N + 1, vector<int>(2));
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = abs((N - 1 - i >= 0 ? a[N - 1 - i] : W) - a[N - 1]);
        dp[i][1] = abs((N - 1 - i >= 0 ? a[N - 1 - i] : Z) - a[N - 1]);
        for (int j = 1; j < i; ++j) {
            dp[i][0] = max(dp[j][1], dp[i][0]);
            dp[i][1] = min(dp[j][0], dp[i][1]);
        }
    }

    cout << dp[N][0] << endl;

    return 0;
}
