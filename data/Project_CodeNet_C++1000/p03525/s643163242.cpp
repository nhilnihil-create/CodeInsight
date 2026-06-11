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
const int MAX_N = 200010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

int cnt[15];

void ng() {
	cout << 0 << "\n";
	exit(0);
}

void solve() {
	int N;
	cin >> N;
	cnt[0]++;
	rep(i, 0, N) {
		int a; cin >> a;
		cnt[a]++;
	}
	vi vec;
	vec.pb(0);
	if(cnt[0] >= 2 || cnt[12] >= 2) ng();
	if(cnt[12]) vec.pb(12);
	vi left;
	rep(i, 1, 12) {
		if(cnt[i] >= 3) ng();
		else if(cnt[i] == 2) {
			vec.pb(i); vec.pb(24 - i);
		}
		else if(cnt[i] == 1) left.pb(i);
	}
	int M = sz(left);
	int res = 0;
	rep(bit, 0, 1 << M) {
		vi tmp = vec;
		rep(i, 0, M) {
			if(bit & (1 << i)) tmp.pb(left[i]);
			else tmp.pb(24 - left[i]);
		}
		int d = 24;
		sort(all(tmp));
		rep(i, 0, sz(tmp)) {
			MIN(d, (24 + tmp[(i + 1) % sz(tmp)] - tmp[i]) % 24);
		}
		// debug(tmp);
		MAX(res, d);
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

