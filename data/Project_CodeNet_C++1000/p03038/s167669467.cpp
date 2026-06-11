#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>> que;
    rep(i, n) {
        int a;
        cin >> a;
        que.push({a, 1});
    }
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        que.push({b, a});
    }

    ll ans = 0;
    while (n > 0) {
        auto p = que.top();
        que.pop();

        rep(i, min(n, p.second)) {
            ans += p.first;
        }
        n -= p.second;
    }

    cout << ans << endl;

    return 0;
}