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

vi get_primes(int n){
    vi res;
    int x = 2;
    while(n >= x*x){
        while(n % x == 0){
            n /= x;
            res.push_back(x);
        }
        x++;
    }
    if(n != 1) res.push_back(n);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    int n; cin >> n;
    map<int,int> mp;
    REP(i,1,n+1){
        auto primes = get_primes(i);
        for(auto prime : primes) ++mp[prime];
    }
    int c2=0,c4=0,c14=0,c24=0,c74=0;
    for(auto p : mp){
        int cnt = p.se;
        if(cnt >= 2) c2++;
        if(cnt >= 4) c4++;
        if(cnt >= 14) c14++;
        if(cnt >= 24) c24++;
        if(cnt >= 74) c74++;
    }

    int ans = 0;
    if(c4 >= 2 && c2 >= 3) ans += c4*(c4-1)/2 * (c2-2);
    if(c14 >= 1 && c4 >= 2) ans += c14 * (c4-1);
    if(c24 >= 1 && c2 >= 2) ans += c24 * (c2-1);
    if(c74 >= 1) ans += c74;
    cout << ans << endl;
    return 0;
}