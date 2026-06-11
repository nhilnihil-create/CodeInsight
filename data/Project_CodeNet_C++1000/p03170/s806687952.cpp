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

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    vector<bool> dp(K + 1);
    for (int i = 0; i < K; ++i) {
        if (dp[i])
            continue;
        for (int j = 0; j < N; ++j) {
            if (i + a[j] > K)
                continue;
            dp[i + a[j]] = true;
        }
    }

    cout << (dp[K] ? "First" : "Second") << endl;

    return 0;
}
