#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11


struct UnionFind{
    vector<int> rank,p,size;
    UnionFind(int n){
        rank.resize(n,0);
        p.resize(n,0);
        size.resize(n,0);
        for(int i = 0; i < n; i++){
            p[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    int root(int x){
        if(x != p[x]){
            p[x] = root(p[x]);
        }
        return p[x];
    }
    bool unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return false;
        if(rank[rx] > rank[ry]){
            p[ry] = rx;
            size[rx] += size[ry];
        }else{
            p[rx] = ry;
            size[ry] += size[rx];
            if(rank[rx] == rank[ry]){
                rank[ry]++;
            }
        }
        return true;
    }
    int tree_size(int x){
        return (size[root(x)]);
    }
};


int main()
{
    int n,m; cin >> n >> m;
    int a[m],b[m];
    int ans = 0;
    rep(i,m) cin >> a[i] >> b[i];
    rep(i,m){
        UnionFind uf(n);
        rep(j,m){
            if(i == j) continue;
            
            uf.unite(a[j]-1,b[j]-1);
        }
        if(uf.tree_size(0) != n) ans++;
    }
    cout << ans << endl;
}