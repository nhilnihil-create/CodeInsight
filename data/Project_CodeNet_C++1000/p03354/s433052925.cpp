#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<vector<ll>> VV;
typedef vector<vector<int>> VVi;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e18+18;
const ll MAX=100005;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define sum(v) accumulate(ALL(v),0)
#define fi first
#define se second

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

struct UnionFind{
    Vec par;
    Vec sz;
    Vec rank;
    UnionFind(ll n):par(n),sz(n),rank(n){
        rep(i,n){
            par[i]=i;
            sz[i]=1;
            rank[i]=0;
        }
    }
    ll root(ll x){
        if(par[x]==x){
            return x;
        }else{
            return root(par[x]);
        }
    }

    void unite(ll x, ll y){
        x = root(x);
        y = root(y);
        if(rank[x]<rank[y]){
            par[x]=y;
            sz[y]+=sz[x];
        }else{
            par[y]=x;
            sz[x]+=sz[y];
            if(rank[x]==rank[y]){
                rank[x]++;
            }
        }
    }

    bool same(ll x, ll y){
        return root(x)==root(y);
    }

    ll size(ll x){
        return sz[root(x)];
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    ll n,m;
    cin>>n>>m;
    UnionFind uf(n);

    Vec p(n);
    rep(i,n){
        cin>>p[i];
        p[i]--;
    }
    rep(i,m){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        uf.unite(p[x],p[y]);
    }
    ll ans=0;

    rep(i,n){
        if(uf.root(i)==uf.root(p[i])){
            ans++;
        }
    }

    cout<<ans<<endl;
    return  0;
}
