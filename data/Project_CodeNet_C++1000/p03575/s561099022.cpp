#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

Int MAX_N;
vector<int> par(500000); //親
vector<int> tree_rank(500000); // 木の深さ
vector<int> sz(500000); //根について，それを含む集合の大きさ

//n要素で初期化
void init(int n) {
    rep(i,n) {
        par[i] = i;
        tree_rank[i] = 0;
        sz[i] = 1;
    }
}

//木の根を求める
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

//xとyの属する集合を併合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    int total = sz[x] + sz[y];
    sz[x] = total;
    sz[y] = total;

    if (tree_rank[x] < tree_rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (tree_rank[x] == tree_rank[y]) tree_rank[x]++;
    }
}

//xとyが同じ集合に属するか否か
bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {


    int N, M;

    cin >> N >> M;

    vector<int> a(M), b(M);
    rep(i,M) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    int cnt = 0;

    rep(i,M) {
        init(N);
        rep(j,M) {
            if (j != i) {
                unite(a[j],b[j]);
            }
        }
        if (sz[find(0)] != N) cnt++;
    }

    cout << cnt << endl;



    return 0;
}
