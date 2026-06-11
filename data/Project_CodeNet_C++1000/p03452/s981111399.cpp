#include <bits/stdc++.h>
using namespace std;
#define __ <<" "<<
#define ___ <<" "
#define bash push_back
#define ALL(x) x.begin(),x.end()
//#define int long long

struct IoSetup {
    IoSetup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout <<fixed<<setprecision(12);
        cerr <<fixed<<setprecision(12);
    }
}IoSetup;

typedef long long ll;
typedef pair < int , int >  pii;
static constexpr const signed int INF = 0x3f3f3f3f;
static constexpr const signed long long LINF = 0x3f3f3f3f3f3f3f3fLL;
static constexpr const signed int SMOD = 1000000007;
static constexpr const signed int NMOD = 998244353;
static constexpr const signed int dx[]={1,0,-1,0,1,1,-1,-1};
static constexpr const signed int dy[]={0,-1,0,1,-1,1,-1,1};

inline bool inside(int x,int y,int w,int h){return (x>=0 && y>=0 && x<w && y<h);}
template<class T>bool chmax(T &a, const T &b){return(a=max(a,b))==b;}
template<class T>bool chmin(T &a, const T &b){return(a=min(a,b))==b;}
inline int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

template<typename T>
struct WeightedUnionFind {
    vector<int> par, rank;
    vector<T> diff_weight;

    // SUM_UNITY アベール群の単位元
    WeightedUnionFind(int n  = 1, T SUM_UNITY = 0) : par(n+5), rank(n+5), diff_weight(n+5) {
        for(int i = 0; i < n+5; i++)
            par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if(par[x] == x) return x;
        int r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }

    T weight(int x){
        root(x);
        return diff_weight[x];
    }
    
    bool same(int x, int y) {return root(x) == root(y);}

    bool merge(int x, int y, T w) {
        w += weight(x) - weight(y);
        if((x=root(x)) == (y=root(y))) return false;
        if(rank[x] < rank[y]) swap(x, y), w = -w;
        rank[x] += (rank[x] == rank[y]);

        par[y] = x, diff_weight[y] = w;
        return true;
    }

    T diff(int x, int y) {return weight(y) - weight(x);
    }
};
        

signed main() {

    int n, m;
    cin >> n >> m;
    int l, r, d;
    WeightedUnionFind<int> uf(n);

    for(int i = 0; i < m; i++) {
        cin >> l >> r >> d;

        if(uf.same(l,r)) {
            if(uf.diff(l,r) != d) {
                cout << "No\n";
                return 0;
            }
        }
        else {
            uf.merge(l, r, d);
        }
    }

    cout << "Yes\n";
    
  
    return 0;
}

