#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct UnionFind
{
private:
    vector<int> par;
    int n;

public:
    UnionFind(int size)
    {
        n = size;
        par.assign(n, -1);
    }
    int root(int node)
    {
        if (par[node] < 0)
            return node;
        return par[node] = root(par[node]);
    }
    bool unite(int a, int b)
    {
        a = root(a);
        b = root(b);
        if(a == b)
            return false;
        if(par[a] > par[b])
            swap(a, b);
        par[a] += par[b];
        par[b] = a;
        return true;
    }
    bool same(int a, int b)
    {
        return root(a) == root(b);
    }
};
int main(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int x, y, z;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        x--;
        y--;
        uf.unite(x, y);
    }
    set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(uf.root(i));
    }
    cout << s.size() << "\n";
}
