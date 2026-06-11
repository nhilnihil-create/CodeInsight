#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int x, y, n, m, ans;
int a[N], root[N];
unordered_map<int, unordered_set<int>> mp;

int find_st(int x) {
    if (root[x] == x) return x;
    return root[x] = find_st(root[x]);
}
void union_st(int x, int y) {
    if (root[x] != root[y])
        root[root[x]] = root[y];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        root[i] = i;
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        if (find_st(a[x]) != find_st(a[y]))
            union_st(a[x], a[y]);
    }
    for (int i = 1; i <= n; ++i) {
        int r = find_st(i);
        mp[r].insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (mp[find_st(a[i])].count(i))
            ++ans;
    }
    cout << ans << endl;

    return 0;
}
