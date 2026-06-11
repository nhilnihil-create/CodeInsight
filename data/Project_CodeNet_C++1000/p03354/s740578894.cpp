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
    vector<int> par;

    UnionFind(int N): par(N) {
        for (int i=0;i<N;++i) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);

        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);

        return rx == ry;
    }
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
