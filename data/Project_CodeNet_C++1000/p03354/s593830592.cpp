#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    /* constructor (initialize) */
    UnionFind(int n){
        parent.resize(n);
        size.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;// completely-disjoint
            size[i] = 1;
            rank[i] = 0;// union by rank
        }
    }

    int root(int x){
        // terminal case
        if(parent[x] == x){
            return x;// by definition
        }

        // recursion
        parent[x] = root(parent[x]);// path compression : keep tree as shallow as possible
        return parent[x];
    }

    void merge(int x, int y){
        int rx = root(x);
        int ry = root(y);

        // if (root(x) == root(y)) do nothing;
        if (rx != ry){
            if(rank[rx] < rank[ry]){
                parent[rx] = ry;// root of merged tree = ry
                size[ry] += size[rx];
            }
            else if(rank[rx] == rank[ry]){
                parent[rx] = ry;
                size[ry] += size[rx];
                rank[ry] += 1;
            }
            else if(rank[rx] > rank[ry]){
                parent[ry] = rx;// root of merged tree = rx
                size[rx] += size[ry];
            }
        }
        return;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    int nodes(int x){
        return size[root(x)];
    }
};

int main(){
    long long int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
        p[i] -= 1;
    }

    vector<int> a(m), b(m);
    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i];
        a[i] -= 1;
        b[i] -= 1;
    }
    
    UnionFind uf(n);
    for(int i=0; i<m; i++){// for each edge
        if(uf.same(a[i],b[i]) == false) uf.merge(a[i], b[i]);
    }
    
    long long int ans = 0;
    for(int i=0; i<n; i++){
        if(uf.same(i,p[i]) == true) ans += 1;
    }
    cout << ans << endl;
    return 0;
}