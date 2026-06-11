#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;
const vector<int> di = {-1,  0, 1, 0};
const vector<int> dj = { 0, -1, 0, 1};

void chmin(int &a, int b) { if (a > b) a = b; }

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

struct UnionFind {
    vector<int> d; // d[a]=bのとき、「aの親がbである」ということを表す。

    UnionFind(int n=0): d(n, -1) {} // 全て根であるとみなす。d[x]==-1のとき、そのノードは根である。

    int find(int x) {
        if (d[x] < 0) return x; // 今の頂点が根ならその値を返す
        return d[x] = find(d[x]); // 経路縮約（メモ化）
    }

    bool unite(int x, int y) { // Minimum Spanning Treeのためにboolを返す実装にしている。
        int rx = find(x);
        int ry = find(y);

        if (rx == ry) return false;
        if (d[rx] > d[ry]) swap(rx, ry); // マイナスサイズなので不等号が逆。xのサイズの方が大きいようにする。
        d[rx] += d[ry]; // 連結成分のサイズを管理するためのコード
        d[ry] = rx; // xにyをくっつける。yの値をxの根とする。
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; }
};


int main(){
    int N, M;
    cin >> N >> M;

    vector<int> P(N);
    rep(i, N) cin >> P.at(i);

    UnionFind tree(N);

    rep(i, M) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        tree.unite(x, y);
    }

    int ans = 0;
    rep(i, N) if (tree.same(i, P.at(i)-1)) ans++;

    cout << ans << endl;
}
