#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
public:
    int S;
    vector <int> par;
    vector <int> siz;
 
    UnionFind(int n){
    	for (int i = 0; i < n; i++) {
    		par.push_back(i);
    		siz.push_back(1);
    	}
        S = n;
    }
 
    int root(int x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }

    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return false;
        if (siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
        S--;
        return true;
    }
 
    bool is_same(int x, int y) {
        return root(x) == root(y);
    }
 
    int size(int x) {
        return siz[root(x)];
    }
	int allsize() {return S;}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
    }

    UnionFind tree(n); // 要素数nのUnion-Find treeを作成

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        tree.unite(x, y); // xのグループとyのグループを併合する
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if (tree.is_same(i, v[i])) { // P[i]とiが同じグル―プに属するかを調べる
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}