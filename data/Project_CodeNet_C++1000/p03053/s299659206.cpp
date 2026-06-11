#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)(n-1); i>=m; i--)
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

int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    int h,w; cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];

    vvi d(h, vi(w, INF));
    queue<pii> Q;
    rep(i,h) rep(j,w) if(a[i][j] == '#'){
        Q.emplace(i, j);
        d[i][j] = 0;
    }
    while(!Q.empty()){
        int i = Q.front().fi;
        int j = Q.front().se;
        Q.pop();
        rep(k,4){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni < 0 || h <= ni) continue;
            if(nj < 0 || w <= nj) continue;
            if(a[ni][nj] == '#') continue;
            if(d[ni][nj] == INF){
                d[ni][nj] = d[i][j] + 1;
                Q.emplace(ni, nj);
            }
        }
    }

    int ans = 0;
    rep(i,h) rep(j,w) ans = max(ans, d[i][j]);
    cout << ans << endl;
    return 0;
}