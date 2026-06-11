#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

struct UnionFind{
    vector<int> d;

    /* 初期化 */
    UnionFind(int n = 0) : d(n , -1) {}

    /* 検索 */
    int find(int x){
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    /* 結合 */
    bool unite(int x, int y){
        x = find(x); y = find(y);
        if (x == y) return false;
        if (x > y) swap(x ,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    /* 結合リスト内か */
    bool same(int x, int y) { return find(x) == find(y); }

    /* サイズ */
    int size(int x) { return -d[find(x)]; }
};

int deg[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    UnionFind tree(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        deg[p[i]] = i;
    }
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        --x; --y;
        tree.unite(x, y);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (p[i] == i + 1) ans++;
        else{
            int pos = deg[i + 1];
            if(tree.same(i, pos)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}