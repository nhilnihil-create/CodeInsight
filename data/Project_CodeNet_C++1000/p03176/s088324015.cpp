#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;
const int TREE_SZ = 524288;

vector<int> mx(TREE_SZ, -2e18);

int get_max(int v, int l, int r, int L, int R) {
    if (R <= l || r <= L) {
        return -2e18;
    }
    if (L <= l && r <= R) {
        return mx[v];
    }
    int m = (l + r) / 2;
    return max(
                get_max(2 * v + 1, l, m, L, R),
                get_max(2 * v + 2, m, r, L, R)
              );
}

void set_elem(int v, int l, int r, int i, int x) {
    mx[v] = max(mx[v], x);
    if (l == r - 1) {
        return;
    }
    int m = (l + r) / 2;
    if (i < m) {
        set_elem(2 * v + 1, l, m, i, x);
    } else {
        set_elem(2 * v + 2, m, r, i, x);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    map<int, int> M;
    for (int i = 0; i < b.size(); i++) {
        M[b[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = M[a[i]];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = max(0ll, get_max(0, 0, n, 0, a[i])) + p[i];
        ans = max(ans, cur);
        set_elem(0, 0, n, a[i], cur);
    }
    cout << ans << endl;
}
