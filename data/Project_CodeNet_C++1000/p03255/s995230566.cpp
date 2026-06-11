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
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 300010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 62;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

struct Ruiseki {
	int N;
	vector<ll> B;
	void init(int n) {
		N = n; B = vector<ll>(N + 1, 0);
	}
	Ruiseki() {}
	Ruiseki(int n) { init(n); }
	void add(int a, ll v) {
		if(a < 0 || N <= a) return;
		B[a + 1] += v;
	}
	void sweep() {
		rep(i, 1, N + 1) B[i] += B[i - 1];
	}
	ll get(int a, int b) { //[a, b)
		if(a >= b) return 0;
		a = max(a, 0); b = min(b, N);
		return B[b] - B[a];
	}
};

int N; ll X;
Ruiseki B;

void solve() {
	cin >> N >> X;
	B.init(N);
	rep(i, 0, N) {
		ll a; cin >> a;
		B.add(i, a);
	}
	B.sweep();

	ll res = linf;

	rep(i, 1, N + 1) {
		int cnt = 3;
		int at = N;
		ll tmp = N * X + i * X + B.get(N - i, N) * 2;
		while(at > 0 && tmp < res) {
			tmp += B.get(at - i, at) * cnt;
			cnt += 2;
			at -= i;
		}
		// debug(i, tmp);
		if(at <= 0) MIN(res, tmp);
	}
	cout << res << "\n";
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
	srand((unsigned int)time(NULL));
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

