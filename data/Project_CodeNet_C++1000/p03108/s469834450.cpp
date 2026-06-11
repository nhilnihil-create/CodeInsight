#include<bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<int> par;
    UnionFind(int n) : par(n, -1){ }
    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool issame(int x, int y){
        return root(x) == root(y);
    }
    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x){
        return -par[root(x)];
    }
};

int main() {
    int N, M; cin >> N >> M;
    vector<pair<int, int>> bri(M);
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        a--,b--;
        bri[i] = make_pair(a,b);
    }
    reverse(bri.begin(), bri.end());

    UnionFind uf(N);
    vector<long long> ans(M, 0);
    for (int i = 0; i < M; i++)
    {
        long long sa = uf.size(bri[i].first), sb = uf.size(bri[i].second);
        if(uf.merge(bri[i].first, bri[i].second)){
            ans[M-i-1] = sa * sb;
        }
    }

    for (int i = 0; i < M; i++)
    {
        if(i > 0) ans[i] += ans[i-1];
    }

    for(int i = 0; i < M; i++) cout << ans[i] << endl;
}