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

int N, M;
int C[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<int> A;
string ans;

void loop(int a, vi vec, int cnt) {
	// debug(a, vec, cnt);
	int n = C[A[0]];
	if(a == sz(A)) {
		if(cnt <= N && (N - cnt) % n == 0) {
			vec[A[0]] = (N - cnt) / n;
			string tmp;
			rer(i, 10, 0) {
				while(vec[i]) {
					tmp += char(i + '0');
					vec[i]--;
				}
			}
			if(sz(tmp) > sz(ans)) {
				ans = tmp;
			}
			else if(sz(tmp) == sz(ans)) {
				bool ok = false;
				rep(i, 0, sz(tmp)) {
					if(tmp[i] > ans[i]) {
						ok = true; break;
					}
					else if(tmp[i] < ans[i]) break;
				}
				if(ok) ans = tmp;
			}
		}
		return;
	}
	rep(i, 0, n) {
		vec[A[a]] = i;
		loop(a + 1, vec, cnt + C[A[a]] * i);
	}
}

void solve() {
	cin >> N >> M;
	map<int, int> D;
	rep(i, 0, M) {
		int a; cin >> a;
		MAX(D[C[a]], a);
	}
	for(auto p: D) A.pb(p.sec);
	ans = "0";
	loop(1, vi(10, 0), 0);
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

