#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20)
#define int long long
#define double long double
const int INF = 1e18, MOD = 2019;

struct UnionFind {
    vector<int> t;
    UnionFind(int size): t(size, -1) {}
    int root(int x) {return t[x] < 0 ? x : t[x] = root(t[x]);}
    int size(int x) {return -t[root(x)];}
    bool is_same(int x, int y) {return root(x) == root(y);}
    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            if(t[y] < t[x]) swap(x, y);
            t[x] += t[y], t[y] = x;
        }
        return x != y;
    }
};

signed main() {
    INCANT;
    int n, a, b;
    cin>>n;
    int c[11111];
    queue<pair<int, int>> q;
    for (int i = 0; i < n - 1; i++) {
        cin>>a>>b;
        q.push(make_pair(a, b));
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin>>c[i];
        sum += c[i];
    }
    sort(c, c + n);
    reverse(c, c + n);
    cout<<sum - c[0]<<endl;
    int res[11111] = {}, now = 0, root = -1;
    UnionFind uf(11111);
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (root == -1) root = p.first;
        if (uf.is_same(root, p.first) || uf.is_same(root, p.second)) {
            if (!res[p.first])  res[p.first]  = c[now], now++;
            if (!res[p.second]) res[p.second] = c[now], now++;
            uf.unite(root, p.first);
            uf.unite(root, p.second);
        } else {
            q.push(p);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout<<res[i]<<' ';
    }
}