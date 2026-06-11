#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct UnionFind {
    vector<int> par, size;
    UnionFind(int x) {
        par.resize(x);
        size.resize(x, 1);
        for(int i = 0; i < x; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int consize(int x) {
        return size[find(x)];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (size[x] < size[y]) {
            par[x] = y;
            size[y] += size[x];
        } else {
            par[y] = x;
            size[x] += size[y];
        }
    }
};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<int>A(M);
    vector<int>B(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;B[i]--;
    }
    UnionFind uf(N);
    int ans = N*(N-1)/2;
    vector<int>ans2(M);
    for(int i = M-1; i >= 0; i--) {
        ans2[i] = ans;
        if(!uf.same(A[i],B[i])) {
            ans-=uf.consize(A[i])*uf.consize(B[i]);
        }
        uf.unite(A[i],B[i]);
    }
    for(int i = 0; i < M; i++) {
        cout << ans2[i] << endl;
    }
}