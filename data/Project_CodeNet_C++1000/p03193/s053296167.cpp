#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
    int N, H, W;
    cin >> N >> H >> W;

    int ans = 0;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        if (H <= a && W <= b)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
