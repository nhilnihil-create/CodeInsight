#include <iostream>
#include <vector>
using namespace std;

struct UF{
    vector<int> par, rank, size;

    void init(int n){
        par.assign(n, 0);
        rank.assign(n, 0);
        size.assign(n, 1);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x != y){
            if(rank[x] < rank[y]){
                par[x] = y;
                size[y] += size[x];
            }else{
                par[y]=x;
                size[x] += size[y];
                if(rank[x]==rank[y]) rank[x]++;
            }
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int get_size(int x){
        return size[find(x)];
    }
};

int main(void){
    int n, m, ans = 0;
    UF uf;
    vector<int> p;
    cin >> n >> m;
    p.assign(n, 0);
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    uf.init(n);
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        uf.unite(--x, --y);
    }
    
    for(int i=0;i<n;i++){
        if(uf.same(i, p[i])) ans++;
    }
    cout << ans << endl;
}
