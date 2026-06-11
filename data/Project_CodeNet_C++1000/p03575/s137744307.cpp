#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> d;
    UnionFind(int n = 0): d(n, -1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -d[find(x)]; }
};

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        UnionFind uf(N);
        for (int j = 0; j < M; j++) {
            if (i == j) continue;
            uf.unite(A[j], B[j]);
        }
        if (!uf.same(A[i], B[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}