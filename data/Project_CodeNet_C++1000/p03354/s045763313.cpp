#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

//-------------------------------------------------
//--Union Find tree
//-------------------------------------------------
class UnionFind
{
private:
    ::std::vector<int> par;
    ::std::vector<int> rank;
public:
    UnionFind(int n):par(n), rank(n){
        for(int i=0; i<n; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    int root(int x){
        if (par[x]==x) return x;
        return par[x] = root(par[x]);
    }
    bool same(int x, int y){
        return root(x)==root(y);
    }
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if (rx==ry) return;
        if (rank[rx]>rank[ry]){
            par[ry] = rx;
        }else{
            par[rx] = ry;
            if (rx==ry) rank[ry]++;
        }
    }
};

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    UnionFind uf(n);
    vi p(n);
    rep(i,n) cin>>p[i];
    rep(i,m){
        int x,y; cin>>x>>y; x--; y--;
        uf.unite(x,y);
    }
    int ans=0;
    rep(i,n){
        if (uf.same(i,p[i]-1)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
