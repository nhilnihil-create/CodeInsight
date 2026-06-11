/*
confirm 0LL and 1LL
confirm cornercases such as 0
confirm times of cin < 10^6
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Pld = pair<ld, ld>;
using Vec = vector<ll>;
using VecP = vector<P>;
using VecB = vector<bool>;
using VecC = vector<char>;
using VecD = vector<ld>;
using VecS = vector<string>;
using Graph = vector<VecP>;
template <typename T>
using Vec1 = vector<T>;
template <typename T>
using Vec2 = vector<Vec1<T> >;
#define REP(i, m, n) for(ll (i) = (m); (i) < (n); ++(i))
#define REPN(i, m, n) for(ll (i) = (m); (i) <= (n); ++(i))
#define REPR(i, m, n) for(ll (i) = (m)-1; (i) >= (n); --(i))
#define REPNR(i, m, n) for(ll (i) = (m); (i) >= (n); --(i))
#define rep(i, n) REP(i, 0, n)
#define repn(i, n) REPN(i, 1, n)
#define repr(i, n) REPR(i, n, 0)
#define repnr(i, n) REPNR(i, n, 1)
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define fs first
#define sc second
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}
template <typename T>
ll pow2(const T n){return (1LL << n);}
template <typename T>
void cosp(const T n){cout << n << ' ';}
template <typename T>
void co(const T n){cout << n << '\n';}
template <typename T1, typename T2>
void co(pair<T1, T2> p){cout << p.fs << ' ' << p.sc << '\n';}
template <typename T>
void co(const Vec1<T> &v){for(T i : v) cosp(i); cout << '\n';}
template <typename T>
void co(initializer_list<T> v){for(T i : v) cosp(i); cout << '\n';}
template <typename T>
void ce(const T n){cerr << n << endl;}
void sonic(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
void setp(const ll n){cout << fixed << setprecision(n);}
constexpr ll INF = 1e9+1;
constexpr ll LINF = 1e18+1;
constexpr ll MOD = 1e9+7;
//constexpr ll MOD = 998244353;
constexpr ld PI = acos(-1);
constexpr ld EPS = 1e-11;

int main(void){
	ll n, k;
	cin >> n >> k;
	Vec a(n);
	rep(i, n) cin >> a[i];
	ll sum = 0;
	rep(i, n) sum += a[i];
	Vec1<bitset<50> > b(n);
	rep(i, n) b[i] = bitset<50>(a[i]);

	Vec cnt(50);
	rep(i, n) rep(j, 50) if(b[i][j]) cnt[j]++;

	bitset<50> l(k);

	Vec2<ll> dp(50, Vec(2));
	repr(i, 50){
		if(pow2(i) > k) continue;
		dp[i][0] = dp[i + 1][0];
		dp[i][1] = dp[i + 1][1];
		if(pow2(i + 1) <= k) dp[i][1] += max(0LL, (n - 2 * cnt[i]) * pow2(i));
		if(l[i]){
			dp[i][0] += (n - 2 * cnt[i]) * pow2(i);
			chmax(dp[i][1], dp[i + 1][0]);
		}
	}
	//co({dp[0][0], dp[0][1]});
	co(sum + max(dp[0][0], dp[0][1]));

	return 0;
}
