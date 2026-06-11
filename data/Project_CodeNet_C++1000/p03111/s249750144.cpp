#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
// Welcome to my source code!

const int INF = 1001001001;

int n, a, b, c;
int l[10];

ll f(int cur, int x, int y, int z) {
    if (cur == n) {
        if (x == 0 || y == 0 || z == 0) return INF;
        return abs(x - a) + abs(y - b) + abs(z - c);
    }
    ll res = INF;
    res = min(res, f(cur + 1, x, y, z));
    res = min(res, f(cur + 1, x + l[cur], y, z) + (x == 0 ? 0 : 10));
    res = min(res, f(cur + 1, x, y + l[cur], z) + (y == 0 ? 0 : 10));
    res = min(res, f(cur + 1, x, y, z + l[cur]) + (z == 0 ? 0 : 10));
    return res;
}

int main() {
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++) cin >> l[i];
    ll ans = f(0, 0, 0, 0);
    cout << ans << endl;
}