#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using Pld = pair<ld, ld>;
using Vec = vector<ll>;
using VecP = vector<pi>;
using VecB = vector<bool>;
using VecC = vector<char>;
using VecD = vector<ld>;
using VecS = vector<string>;
using Graph = vector<VecP>;
#define REP(i, m, n) for(ll (i) = (m); (i) < (n); ++(i))
#define REPR(i, m, n) for(ll (i) = (m); (i) > (n); --(i))
#define rep(i, n) REP(i, 0, n)
#define R cin>>
#define repr(i, n) REPR(i, n, 0)
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define in(a) insert(a)
#define P(p) cout<<(p)<<endl;
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define SORT(a) sort((a).begin(), (a).end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
void sonic(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
void setp(const ll n){cout << fixed << setprecision(n);}
const ll INF = 1e9+1;
const ll LINF = 1e18+1;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ld PI = acos(-1);
const ld EPS = 1e-11;
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
template<typename T> void co(T e){cout << e << "\n";}
template<typename T> void co(const vector<T>& v){for(const auto& e : v)
    { cout << e << " "; } cout << "\n";}
ll gcd(ll a, ll b) {
    if (a < b)swap(a, b);
    if (b == 0) return a;
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a * b / g;
}
bool prime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n%i == 0)return false;
    }
    return n != 1;
}

const int n = 3000;
int fac[n];
int inv[n];

ll pow(int a, int n, int mod){
    if(n == 1) return a;
    if(n%2 == 0) return pow(1LL*a*a%MOD, n/2, MOD);
    return 1LL*a*pow(1LL*a*a%MOD, n/2, MOD)%MOD;
}


void init(int n){
    fac[0] = 1;
    REP(i, 1, n + 1) fac[i] = 1LL * fac[i - 1] * i % MOD;
    inv[n] = pow(fac[n], MOD - 2, MOD);
    REPR(j, n - 1, -1) inv[j] = 1LL * inv[j + 1] * (j + 1) % MOD;
}

int comb(ll n, ll k){
    if(k>n) return 0;
    return 1LL * fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}


pair<int, vi> bfs(const vvi& g, int x){
    vi d(g.size(), -1);
    queue<int> q; q.push(x);
    int u = -1;
    d[x] = 0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(auto& v:g[u]){
            if(d[v] != -1) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
    return mp(u, d);
}


vi dist(const vvi& g){
    auto p1 = bfs(g, 0);
    auto p2 = bfs(g, p1.first);
    auto p3 = bfs(g, p2.first);
    vi res(g.size());
    rep(i, g.size()) res[i] = max(p2.second[i], p3.second[i]);
    sort(res.begin(), res.end());
    return res;
}

vvi readGraph(){
    int n;
    cin >> n;
    vvi g(n);
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
}

int grid[300][300];
map<int, pi> D1;
map<int, int> D2;

int main(){
    int h, w, d, q, x;

    cin >> h >> w >> d;
    rep(i, h) rep(j, w) {
        cin >> x;
        D1[x] = {i, j};
    }
    REP(i, 1, h*w+1) if(i-d>0) D2[i] = D2[i-d] + abs(D1[i].first - D1[i-d].first) + abs(D1[i].second - D1[i-d].second);
    cin >> q;
    rep(k, q){
        int l, r;
        cin >> l >> r;
        co(D2[r] - D2[l]);
    }
}
