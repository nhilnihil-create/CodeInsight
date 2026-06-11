#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pll = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, m, n) for(ll i = m; i > n; i--)
#define Rep(i, m, n) for(ll i = m; i < n; i++)
#define all(vec) vec.begin(), vec.end()
#define lmax(x, y) max<ll>(x, y)
#define lmin(x, y) min<ll>(x, y)
#define tmax(x, y, z) lmax((x), lmax((y), (z)))
#define tmin(x, y, z) lmin((x), lmin((y), (z)))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define ZERO(a) memset(a, 0, sizeof(a))
const ll INF = 1LL << 60;
const ll MM = 1000000000; const ll MOD = MM + 7; const ll MMM=9223372036854775807;//2^63 -1
#define ADD(a,b) a = (a + ll(b)) % MOD
#define MUL(a,b) a = (a * ll(b)) % MOD
ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}
ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true;} return false;}
template<typename A, size_t N, typename T> void FILL(A (&array)[N], const T &val){ fill( (T*)array, (T*)(array+N), val );}
// struct edge{ ll from, to, cost; };
// struct edge{ ll to, cost; };
// using Graph = vector<vector<ll>>;  // 重み無し
// using Graph = vector<edge>;  // 辺
// using Graph = vector<vector<edge>>;  // 重み付き
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
ll ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//cout << fixed << setprecision(10);
// priority_queue<ll, vector<ll>, greater<ll>> pq;


int main(){
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> w(n+1), b(n+1);
    w[0] = 0, b[0] = 0;
    Rep(i, 1, n+1){
        if(s[i-1] == '#'){
            w[i] = w[i-1];
            b[i] = b[i-1] + 1;
        }
        else{
            w[i] = w[i-1] + 1;
            b[i] = b[i-1];
        }
    }
    ll ans = INF;
    rep(i, n+1){
        chmin(ans, w[n]-w[i] + b[i]-b[0]);
    }
    cout << ans << endl;
}
