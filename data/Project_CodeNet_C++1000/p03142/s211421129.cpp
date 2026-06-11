#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)((n)-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T>
string join(const vector<T>&v, string del=", "){ stringstream s;
    for(auto x : v) s << del << x; return s.str().substr(del.size());
}
template<typename T>
ostream& operator<<(ostream& o, const vector<T>&v){
    if(v.size()) o << "[" << join(v) << "]"; return o;
}
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T> >&vv){
    int l = vv.size();
    if(l){ o<<endl; rep(i,l) o << (i==0 ? "[ " : ",\n  " ) << vv[i] << (i==l-1 ? " ]" : ""); }
    return o;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p){
    return o << "(" << p.first << ", " << p.second << ")";
}
inline void _debug(){cerr<<endl;}
template<class First, class... Rest>
void _debug(const First& first, const Rest&... rest){cerr<<first<<" ";_debug(rest...);}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const double PI = (1*acos(0.0));
const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

int n,m;
vvi g;
vi tsort_Kahn(){
    vi indeg(n, 0);
    vi dist(n, -1);
    stack<int> S;
    rep(i,n) for(auto v : g[i]) indeg[v]++;
    rep(i,n) if(indeg[i] == 0) S.push(i), dist[i] = 0;

    vi res;
    while(S.size()>0){
        int v = S.top(); S.pop();
        res.emplace_back(v); for(auto u : g[v]){
            indeg[u]--;
            if(indeg[u] == 0) S.push(u), dist[u] = max(dist[u], dist[v] + 1);
        }
    }
    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    cin >> n >> m;
    g = vvi(n+1);
    vi cnt(n+1);
    rep(i,n-1+m){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        cnt[b]++;
    }
    n++;
    REP(i,1,n) if(cnt[i] == 0) g[0].push_back(i);
    auto dist = tsort_Kahn();

    vi par(n, 0);
    REP(v,1,n){
        for(auto u : g[v]){
            if(dist[u] == dist[v] + 1) par[u] = v;
        }
    }
    REP(v,1,n){
        cout << par[v] << endl;
    }
    return 0;
}