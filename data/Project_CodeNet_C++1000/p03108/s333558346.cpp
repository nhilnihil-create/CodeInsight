#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int maxn = 1e5 + 13;

int root[maxn], sz[maxn];
int n, m;
int64_t ans = 0;

int dsu_find (int a) {
    if (a == root[a])
        return a;
    return root[a] = dsu_find(root[a]);
}

void dsu_unite (int a, int b) {
    a = dsu_find(a);
    b = dsu_find(b);
    if (a != b) {
        ans -= int64_t(sz[a]) * int64_t(sz[b]);
        if (sz[b] > sz[a]) 
            swap(b, a);
        root[b] = a;
        sz[a] += sz[b];
    }
}

signed main () {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
        root[i] = i, sz[i] = 1;
    vector < pair < int, int > > edge(m);
    for (int i = 0; i < m; ++i)
        cin >> edge[i].first >> edge[i].second;
    deque < int > answer;
    ans = (int64_t(n) * int64_t(n - 1)) / 2;
    for (int i = m - 1; i >= 0; --i) {
        answer.push_front(ans);
        dsu_unite(edge[i].first, edge[i].second);
    }
    for (int i = 0; i < int(answer.size()); ++i)
        cout << answer[i] << '\n';
}
