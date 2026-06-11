#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

class DisjointSet{
    public:
    vector<ll> rank,p,sz;
    DisjointSet(){}
    DisjointSet(ll size){ //作られうる木の頂点数の最大値を入れる。
        rank.resize(size,0);
        p.resize(size,0);
        sz.resize(size,0);
        rep(i,size) makeSet(i);
    }
    void makeSet(ll x){ //xだけが属する木を作る。
        p[x]=x;
        rank[x]=0;
    }
    bool same(ll x,ll y){ //xとyが同じ木に属するかどうか
        return findSet(x)==findSet(y);
    }
    void unite(ll x, ll y){
        link(findSet(x),findSet(y));
    }
    void link(ll x, ll y){ //rankが大きい方の根に小さい方の根をつける。
        if(rank[x]>rank[y]){
            p[y]=x;
        }
        else{
            p[x]=y;
            if(rank[x]==rank[y]){
                rank[y]++; //xとyの木のrankが同じであれば、統合するとrankが1増える。
            }
        }
        sz[x]+=sz[y];
        sz[y]=sz[x];
    }
    ll findSet(ll x){ //xが属する木の根の番号を返す
        if(x!=p[x]){
            p[x]=findSet(p[x]);
        }
        return p[x];
    }
};


int main()
{
    ll n,m;
    cin >> n >> m;
    DisjointSet ds=DisjointSet(n+1);
    vector<ll> x(m),y(m),z(m);
    rep(i,m){
        cin >> x[i] >> y[i] >> z[i];
        x[i]--;
        y[i]--;
        ds.unite(x[i],y[i]);
    }
    set<ll> ans;
    rep(i,n){
        ans.insert(ds.findSet(i));
    }
    cout << ans.size() << endl;
    return 0;
} 