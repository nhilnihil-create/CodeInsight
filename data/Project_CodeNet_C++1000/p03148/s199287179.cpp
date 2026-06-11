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
void co(void){cout << '\n';}
template <typename T>
void co(const T n){cout << n << '\n';}
template <typename T1, typename T2>
void co(pair<T1, T2> p){cout << p.fs << ' ' << p.sc << '\n';}
template <typename T>
void co(const Vec1<T> &v){for(T i : v) cosp(i); co();}
template <typename T>
void co(initializer_list<T> v){for(T i : v) cosp(i); co();}
template <typename T>
void ce(const T n){cerr << n << endl;}
template <typename T>
void ce(initializer_list<T> v){for(T i : v) cerr << i << ' '; cout << endl;}
void sonic(){ios::sync_with_stdio(false); cin.tie(0);}
void setp(const ll n){cout << fixed << setprecision(n);}
constexpr int INF = 1e9+1;
constexpr ll LINF = 1e18+1;
constexpr ll MOD = 2019;
//constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-11;
const ld PI = acos(-1);

int main(void){
	ll n, k;
	cin >> n >> k;
	VecP a(n);
	rep(i, n) cin >> a[i].sc >> a[i].fs;

	sort(all(a));
	reverse(all(a));
	Vec cs(n);
	rep(i, n){
		if(i == 0) cs[i] = a[i].fs;
		else cs[i] = cs[i - 1] + a[i].fs;
	}

	VecB used(n, false);
	unordered_set<ll> ust;

	ll ans = 0, sum = 0;
	ll l = k - 1, r = 0;
	repn(i, k){
		while(r < n && ust.find(a[r].sc) != ust.end()) r++;
		if(r >= n) break;
		ust.insert(a[r].sc);
		used[r] = true;
		if(r <= l) chmax(ans, cs[l] + i * i);
		else{
			sum += a[r].fs;
			while(used[l]){
				sum += a[l--].fs;
			}
			l--;
			if(l < 0) break;
			chmax(ans, cs[l] + sum + i * i);
		}
		ce({l, r, ans});
	}
	co(ans);

	return 0;
}
