#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

struct UnionFind {
    vector<int> parent;
    
    UnionFind(int n) : parent(n, -1) { }
    void init(int n) { parent.assign(n, -1); }
    
    int root(int x) {
        if (parent[x] < 0) return x;
        else return parent[x] = root(parent[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (parent[x] > parent[y]) swap(x, y); // merge technique
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
    
    int size(int x) {
        return -parent[root(x)];
    }
};
 
int main(){
    int N,M;
    cin >> N >> M;
    UnionFind U(N);
    vector<int> P(N);
    rep(i,N){
        cin >> P[i];
        P[i]--;
    }
    rep(i,M){
        int x,y;
        cin >> x >> y;
        x--,y--;
        U.merge(x,y);
    }

    int res = 0;
    rep(i,N){
        if(U.issame(i,P[i])) res++;
    }

    cout << res << endl;

    return 0;
}