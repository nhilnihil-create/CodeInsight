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

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    int x,y,z,k;
    cin >> x >> y >> z >> k;
    vl a(x),b(y),c(z);
    rep(i,x) cin >> a[i];
    rep(i,y) cin >> b[i];
    rep(i,z) cin >> c[i];

    vl bc;
    rep(i,y) rep(j,z) bc.push_back(b[i]+c[j]);
    sort(rall(bc));

    priority_queue<tuple<ll,ll,ll>> Q;
    rep(i,x) Q.emplace(a[i]+bc[0], i, 0);
    rep(i,k){
        auto t = Q.top(); Q.pop();
        ll ans = get<0>(t);
        ll xi = get<1>(t);
        ll bci = get<2>(t);
        if(bci < y*z-1){
            Q.emplace(a[xi]+bc[bci+1], xi, bci+1);
        }
        cout << ans << endl;
    }
    return 0;
}