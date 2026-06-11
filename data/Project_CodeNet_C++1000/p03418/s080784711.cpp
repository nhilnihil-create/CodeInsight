#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    ll ans = 0;
    for (int i = K + 1; i <= N; ++i) {
        ans += N / i * (i - K);
        ans += max(N % i - K + 1, 0);
        if (K == 0)
            ans--;
    }

    cout << ans << endl;

    return 0;
}
