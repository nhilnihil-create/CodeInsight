// 7/25
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    rep(i, N) cin >> x[i];

    int ans = 1e9;

    for (int left = 0; left + K <= N; left++) {
        // xi〜xi+Kまで。
        
        int right = left + K - 1;

        int dist = x[right] - x[left];

        // 先にleftから。
        ans = min(ans, dist + abs(x[left]));

        // 先にrightから。
        ans = min(ans, dist + abs(x[right]));

    }

    cout << ans << endl;
    return 0;
}