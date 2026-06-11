#include <bits/stdc++.h>
using namespace std;

template <typename T>
class DisjointSet {
   public:
    map<T, T> p;
    map<T, int> rank;
    DisjointSet() {
        p.clear();
        rank.clear();
    }
    DisjointSet(vector<T> elements) {
        p.clear();
        rank.clear();
        for (int i = 0; i < elements.size(); i++) {
            makeSet(elements[i]);
        }
    }
    void makeSet(T x) {
        p[x] = x;
        rank[x] = 0;
    }
    bool same(T x, T y) { return findSet(x) == findSet(y); }
    void unite(T x, T y) { link(findSet(x), findSet(y)); }
    T findSet(T x) {
        if (x != p[x]) {
            p[x] = findSet(p[x]);
        }
        return p[x];
    }

   private:
    void link(T x, T y) {
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> elem;
    for (int i = 1; i <= N; i++) elem.push_back(i);
    DisjointSet<int> DS(elem);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        DS.unite(x, y);
    }
    set<int> p;
    for (int i = 1; i <= N; i++) {
        p.insert(DS.findSet(i));
    }
    int ans = p.size();
    cout << ans << endl;
    return 0;
}
