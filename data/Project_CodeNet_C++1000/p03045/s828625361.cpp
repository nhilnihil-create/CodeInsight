#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

struct UnionFind {
    UnionFind(int n) {
        parent.resize(n, -1);
        weight.resize(n, 0);
    }
    int find(int x) {
        if (parent[x] < 0)
            return x;
        else
            return parent[x] = find(parent[x]);
    }
    bool isSame(int x, int y) { return find(x) == find(y); }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            weight[x]++;
            return;
        }
        if (parent[x] < parent[y])
            swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        weight[x] += weight[y] + 1;
    }
    int getSize(int x) { return -parent[find(x)]; }
    int getWeight(int x) { return weight[find(x)]; }

private:
    vector<int> parent;
    vector<int> weight;
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        uf.unite(x, y);
    }

    set<int> p;
    for (int i = 0; i < N; i++) {
        p.insert(uf.find(i));
    }
    cout << p.size() << endl;
}
