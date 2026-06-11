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

struct Sieve{
    int n;
    vi f, primes;
    Sieve(int n): n(n), f(n+1){
        f[0] = f[1] = -1;
        for(ll i=2; i<=n; i++){
            if(f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for(ll j=i*i; j<=n; j += i){
                if(!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x){ return f[x] == x; }
    vi prime_factor(int x){
        vi res;
        while(x != 1){
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<pii> factor(int x){
        vi pf = prime_factor(x);
        if(pf.size() == 0) return {};
        vector<pii> res(1, pii(pf[0], 0));
        for(int p : pf){
            if(res.back().first == p){
                res.back().second++;
            }else{
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    auto sieve = Sieve(56000);
    int n; cin >> n;

    vi ans;
    int idx = 1;
    while(ans.size() < n){
        int p = sieve.primes[idx];
        if(p % 5 == 1) ans.push_back(p);
        idx++;
    }
    cout << join(ans, " ") << endl;
    return 0;
}