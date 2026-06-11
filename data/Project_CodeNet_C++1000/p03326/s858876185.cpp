#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<int>>;
const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<ll>> xyz(N, vector<ll>(3));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> xyz[i][j];

    ll ans = LLONG_MIN;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < N; ++j) {
            ll tmp = 0;
            for (int k = 0; k < 3; ++k)
                tmp += xyz[j][k] * (i & (1 << k) ? -1 : 1);
            que.push(tmp);
            if (que.size() > M)
                que.pop();
        }
        ll sum = 0;
        while (!que.empty()) {
            sum += que.top();
            que.pop();
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
