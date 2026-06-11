#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long
constexpr int INF = 1000000000 + 8;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    int ans = INF;

    // 連続するK個のろうそくに火をつけるのが最適→それを全列挙

    for (int i = 0; i < n - k + 1; i++) {
        const int l = x[i], r = x[i + k - 1];

        int now = abs(l - r) + min(abs(l), abs(r));
        ans = min(ans, now);
    }

    cout << ans << endl;
}
