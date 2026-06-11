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

//T とか u とかわけわからん変数が大量にある。
//場合分けが煩雑になってしまった。構成法がダメだったから。
// int Q;
//
// void solve() {
// 	cin >> Q;
// 	while(Q--) {
// 		ll a, b;
// 		cin >> a >> b;
// 		ll lv = 1, rv = 1000000000;
// 		while(rv - lv > 1) {
// 			ll m = (lv + rv) / 2;
// 			if(a * b - 1 > m * m + m) lv = m;
// 			else rv = m;
// 		}
// 		ll T = lv;
// 		debug(T);
// 		int minus = 0;
// 		ll u = (a * b - 1) / b;
// 		if(u) debug(u, (a * b - 1) / u, (a * b - 1) / (u + 1));
// 		if(u != 0 && (a * b - 1) / u - (a * b - 1) / (u + 1) <= 1) minus++;
// 		ll d = (a * b - 1) / a;
// 		ll l = (a * b - 1) / (a + 1), r = (a != 1 ? (a * b - 1) / (a - 1) : d);
// 		if(l == d && d == r) minus++;
// 		if(a == u) minus--;
// 		else cout << (a * b - 1) / (T + 1) + T - minus << "\n";
// 	}
// }

ll Q, A, B;

void solve() {
	cin >> Q;
	while(Q--) {
		cin >> A >> B;
		if(A > B) swap(A, B);
		if(B - A <= 1) cout << 2 * A - 2 << "\n";
		else {
			ll C = ll(sqrt(A * B) - eps);
			if(C * (C + 1) >= A * B) cout << 2 * C - 2 << "\n";
			else cout << 2 * C - 1 << "\n";
		}
	}
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

