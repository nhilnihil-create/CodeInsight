#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 




////////////////////////////////////////////////////////

struct UnionFind{
    vector<int> rank, p;
    UnionFind(int N){
            rank.resize(N, 0);
            p.resize(N, 0);
            for(int i=0; i < N; i++) makeSet(i);
    }
    void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
    }
    bool same(int x, int y){
            return findSet(x) == findSet(y);
    }
    void unite(int x, int y){
            link(findSet(x), findSet(y));
    }
    void link(int x, int y){
            if(rank[x] > rank[y]){
                    p[y] = x;
            }else{
                    p[x] = y;
                    if(rank[x] == rank[y]){
                            rank[y]++;
                    }
            }
    }
    int findSet(int x){
            if(x != p[x]){
                    p[x] = findSet(p[x]);
            }
            return p[x];
    }
};

int main() {
    ll n, m; cin >> n >> m;
    UnionFind ds = UnionFind(n+1);

    Vl x(m), y(m), z(m);
    rep(i, 0, m){
        cin >> x[i] >> y[i] >> z[i];
    }
    rep(i, 0, m){
        ds.unite(x[i], y[i]);
    }
    // Rep(i, 1, n) cout << ds.findSet(i) << " ";
    // coel;
    ll ans = 0;
    set<ll> se;
    Rep(i, 1, n){
        if(ds.findSet(i) == i){
            ans++;
        }
    }
    co(ans);

    return 0;
}
