#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<P> VP;
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

struct BipartiteMatching {
    vector< vector< int > > graph;
    vector< int > match, alive, used;
    int timestamp;

    BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool dfs(int idx) {
        used[idx] = timestamp;
        for(auto &to : graph[idx]) {
            int to_match = match[to];
            if(alive[to] == 0) continue;
            if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
                match[idx] = to;
                match[to] = idx;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching() {
        int ret = 0;
        for(int i = 0; i < graph.size(); i++) {
            if(alive[i] == 0) continue;
            if(match[i] == -1) {
                ++timestamp;
                ret += dfs(i);
            }
        }
        return ret;
    }

    void output() {
        for(int i = 0; i < graph.size(); i++) {
            if(i < match[i]) {
                cout << i << "-" << match[i] << endl;
            }
        }
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    ll n;
    cin>>n;
    VP R(n);
    VP B(n);
    rep(i,n){
        ll a,b;
        cin>>a>>b;
        R[i] = mp(a,b);
    }
    rep(i,n){
        ll a,b;
        cin>>a>>b;
        B[i] = mp(a,b);
    }

    BipartiteMatching bm(n+n);
    rep(i,n){
        rep(j,n){
            if(B[j].fi>R[i].fi && B[j].se>R[i].se){
                bm.add_edge(i,j+n);
            }
        }
    }
    cout<<bm.bipartite_matching()<<endl;
    return  0;
}
