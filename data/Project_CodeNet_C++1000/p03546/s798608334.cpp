#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 1001001001001001001;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> cost(10, vector<ll>(10, INF));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ll a;
            cin >> a;
            cost[i][j] = a;
        }
    }
    for (int i = 0; i < 10; ++i) {
        cost[i][i] = 0;
    }
    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ll x;
            cin >> x;
            if (x == -1) continue;
            ans += cost[x][1];
        }
    }
    cout << ans << endl;
}
