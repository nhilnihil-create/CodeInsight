#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int r[N], cnt[N], a[N], b[N];
int n, m;
ll ans[N], res;

int find_set(int x) {
    int rx = r[x];
    if (x == rx) return x;
    return r[x] = find_set(rx);
}

void union_set(int x, int y) {
    int rx = find_set(x);
    int ry = find_set(y);
    if (rx == ry) return;

    res -= cnt[rx] * cnt[ry];

    if (cnt[rx] > cnt[ry]) {
        cnt[rx] += cnt[ry];
        r[ry] = rx;
    } else {
        cnt[ry] += cnt[rx];
        r[rx] = ry;
    }
}

int main() {
    cin >> n >> m;
    iota(r, r + n, 0);
    fill(cnt, cnt + n, 1);
    res = 1LL * n * (n - 1) / 2;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = m - 1; i >= 0; --i) {
        ans[i] = res;
        union_set(a[i] - 1, b[i] - 1);
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
