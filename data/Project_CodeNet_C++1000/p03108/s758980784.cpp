#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

struct UnionFind {
    vector<int> par;
    vector<int> weight;

    UnionFind(int N) : par(N), weight(N) {
        REP(i, N) {
            par[i] = i;
            weight[i] = 1;
        }
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    ll unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return 0;
        par[rx] = ry;
        ll res = weight[rx] * weight[ry];
        weight[ry] += weight[rx];
        return res;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    ll N, M; cin >> N >> M;
    vector<int> A(M), B(M); REP(i, M) {cin >> A[i] >> B[i]; A[i]--; B[i]--;}

    UnionFind tree(N);
    vector<ll> inconvinience(M);
    inconvinience[M-1] = N * (N-1) / 2;
    for (int i = M-1; i > 0; i--) {
        inconvinience[i-1] = inconvinience[i] - tree.unite(A[i], B[i]);
    }
    REP(i, M) PRINT(inconvinience[i]);
    return 0;
}