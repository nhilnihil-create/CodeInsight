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
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

int N, A, B;
int ans[MAX_N];

void solve() {
	cin >> N >> A >> B;
	if(N == 1) {
		if(A == 1 && B == 1) {
			cout << 1 << "\n";
		}
		else cout << "-1\n";
		return;
	}
	bool swaped = false;
	if(A < B) {
		swap(A, B);
		swaped = true;
	}
	vector<int> cnt(B, 1);
	int n = N;

	if((N + A - 1) / A > B) {
		cout << "-1\n";
		return;
	}

	rep(i, 0, (N + A - 1) / A) {
		cnt[i] = min(A, n);
		n -= A;
	}

	int r = B - (N + A - 1) / A;

	rep(i, 1, (N + A - 1) / A) {
		if(cnt[i] - 1 >= r) {
			cnt[i] -= r;
			r = 0;
		}
		else {
			cnt[i] = 1;
			r -= (cnt[i] - 1);
		}
	}

	if(r != 0) {
		cout << "-1\n";
		return;
	}

	int at = 0;
	int from = N - 1;

	rep(i, 0, B) {
		rep(j, 0, cnt[i]) {
			ans[at] = from - cnt[i] + j + 1;
			at++;
		}
		from -= cnt[i];
	}

	if(swaped) reverse(ans, ans + N);
	rep(i, 0, N) {
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";
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

