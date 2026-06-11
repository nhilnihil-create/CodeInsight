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

    int N;
    cin >> N;
    vector<ll> asum(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> asum[i];
        asum[i] += asum[i - 1];
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 1e17));
    vector<vector<int>> spl(N + 1, vector<int>(N + 1));
    for (int w = 0; w <= N; ++w) {
        for (int l = 0; l + w <= N; ++l) {
            int r = l + w;
            if (w <= 1) {
                dp[l][r] = 0;
                spl[l][r] = l;
                continue;
            }

            for (int mid = spl[l][r - 1]; mid <= spl[l + 1][r]; ++mid) {
                ll tmp = dp[l][mid] + dp[mid][r] + asum[r] - asum[l];
                if (tmp < dp[l][r]) {
                    dp[l][r] = tmp;
                    spl[l][r] = mid;
                }
            }
        }
    }

    cout << dp[0][N] << endl;

    return 0;
}
