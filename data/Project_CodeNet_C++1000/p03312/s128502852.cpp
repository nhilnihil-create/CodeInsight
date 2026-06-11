#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cerr << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cerr<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 500010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = (1 << 30) - 1;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
mt19937 rng; //use it by rng() % mod, shuffle(all(vec), rng)
///////////////////////////////////////////////////////////////////////////////////////////////////

int N;
ll A[MAX_N];
ll S[MAX_N];
pl D[MAX_N], E[MAX_N];

void pre(pl C[MAX_N]) {
	S[0] = A[0];
	rep(i, 1, N) S[i] = A[i] + S[i - 1];

	for(int i = 1; i < N; i++) {
		ll diff = linf;
		int at = lower_bound(S, S + N, (S[i] + 1) / 2) - S;
		MIN(diff, abs(S[i] - S[at] * 2));
		MIN(diff, abs(S[i] - S[at - 1] * 2));
		C[i] = make_pair((S[i] - diff) / 2, (S[i] + diff) / 2);
	}
}

void solve() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];
	pre(D);
	reverse(A, A + N);
	pre(E);
	reverse(E, E + N);
	ll ans = linf;
	for(int i = 1; i <= N - 3; i++) {
		ll l = linf, r = -linf;
		MIN(l, D[i].fst);
		MIN(l, E[i + 1].fst);
		MAX(r, D[i].sec);
		MAX(r, E[i + 1].sec);
		MIN(ans, r - l);
	}
	cout << ans << "\n";
}

uint32_t rd() {
	uint32_t res;
#ifdef __MINGW32__
	asm volatile("rdrand %0" :"=a"(res) ::"cc");
#else
	res = std::random_device()();
#endif
	return res;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
    cerr << fixed;
	cerr.precision(6);
	rng.seed(rd());
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
	if(!freopen("in.txt", "rt", stdin)) return 1;
#endif	
	solve();
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}

