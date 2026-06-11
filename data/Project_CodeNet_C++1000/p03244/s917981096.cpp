#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
const int INF_N = 1e+9;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

//繰り返し二乗法
ll mod_pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

//逆元(Eucledean algorithm)
ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
using mP = pair<modint, modint>;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };




void solve() {
    int N; cin >> N;
    vec a(N);
    rep(i, N) cin >> a[i];
    unordered_map<int, int> m1, m2;
    rep(i, N){
        if(i%2 == 0) m1[a[i]]++;
        else m2[a[i]]++;
    }
    vector<P> p1, p2;
    for(auto p: m1){
        p1.push_back(make_pair(p.second, p.first));
    }
    for(auto p: m2){
        p2.push_back(make_pair(p.second, p.first));
    }
    sort(p1.rbegin(), p1.rend());
    sort(p2.rbegin(), p2.rend());
    if(p1.size() == 1){
        if(p2.size() == 1){
            if(p1[0].second == p2[0].second){
                cout << N/2 << endl;
            }else{
                cout << 0 << endl;
            }
        }else{
            if(p1[0].second == p2[0].second){
                cout << N/2 - p2[1].first << endl;
            }else{
                cout << N/2 - p2[0].first << endl;
            }
        }
    }else{
        if(p2.size() == 1){
            if(p1[0].second == p2[0].second){
                cout << N/2 - p1[1].first << endl;
            }else{
                cout << N/2 - p1[0].first << endl;
            }
        }else{
            if(p1[0].second == p2[0].second){
                cout << min(N-p1[0].first-p2[1].first, N-p1[1].first-p2[0].first) << endl;
            }else{
                cout << N-p1[0].first-p2[0].first << endl;
            }
        }
    }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //cout << fixed << setprecision(10);
  //init_f();
  //init();
  //int t; cin >> t; rep(i, t)solve();
  solve();
//   stop
    return 0;
}
