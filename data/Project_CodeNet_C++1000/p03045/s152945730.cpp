#include <bits/stdc++.h>
using namespace std;

class union_find {
private:
    vector<int> parent;
public:
    union_find(int n) : parent(n, -1) {}
    ~union_find() {}
    void link(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (parent[x] > parent[y])
            swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
    }
    int find(int x) {
        if (parent[x] < 0)
            return x;
        return parent[x] = find(parent[x]);
    }
    int count(int x) {
        return -parent[find(x)];
    }
    bool linked(int x, int y) {
        return find(x) == find(y);
    }
};

int main()
{
    int N, M; cin >> N >> M;
    union_find uf(N+1);
    for (int i = 0; i < M; i++) {
        int x, y, z; cin >> x >> y >> z;
        uf.link(x, y);
    }
    set<int> s;
    for (int i = 1; i <= N; i++) {
        s.insert(uf.find(i));
    }

    cout << s.size() << endl;
}
