#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647);
static const ll LLINF = (9223372036854775807);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Printer{
    template<class T>
    void print(T x){
        cout << x << endl;
    }

    template<class T>
    void print(vector<T> v){
        rep(i, v.size()){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    template<class T>
    void print(vector<vector<T> > vv){
        rep(i, vv.size()){
            rep(j, vv[i].size()){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void print(pair<int, int> p){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
};
using namespace Printer;

//--global--//


class UnionFind{
    public:
        vector<ll> par; // 親
        vector<ll> rank; // 木の深さ
        ll numComponent; // 木の数
        void init(ll n){
            par.resize(n);
            rank.assign(n, 1LL);
            for(ll i=0; i<n; ++i) par[i] = i;
            numComponent = n;
        }

        ll findRoot(ll x){
            if(par[x] == x) return x;
            else return par[x] = findRoot(par[x]);
        }

        void unite(ll x, ll y){
            x = findRoot(x);
            y = findRoot(y);
            if(x == y) return;
            if(rank[x] < rank[y]) swap(x, y);
            rank[x] += rank[y];
            par[y] = x;
            numComponent--;
            return;
        }

        bool same(ll x, ll y){
            return findRoot(x) == findRoot(y);
        }

        ll size(ll x){
            return rank[findRoot(x)];
        }
};



//----------//

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//

    int n, m;
    cin >> n >> m;
    vector<int> p;
    rep(i, n){
        int a;
        cin >> a;
        a--;
        p.push_back(a);
    }
    UnionFind unionFind;
    unionFind.init(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        unionFind.unite(a, b);
    }
    int ans = 0;
    rep(i, n){
        if(unionFind.same(p[i], p[p[i]])){
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}
