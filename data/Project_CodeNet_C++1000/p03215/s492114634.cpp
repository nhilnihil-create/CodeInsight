#define LOCAL
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rrep(i, n) for(int i=(n-1); i>=0; --i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define memr(dp, val) memset(dp, val, sizeof(dp))
using namespace std;
typedef long long ll;
static const int INTINF = (INT_MAX >> 1); // 10^9 + 10^7
static const ll LLINF = (LLONG_MAX >> 1);
static const int MAX = 100001;
static const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool int_ceil(T a, T b) { T res = a / b; if(a % b != 0) res++; return res; }
template<typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool b) { return b ? "true" : "false"; }
template <size_t N> string to_string(bitset<N> bs) {
  string res;
  for (size_t i = 0; i < N; ++i) res += '0' + bs[i];
  return res;
}
string to_string(vector<bool> v) {
  string res = "{";
  for (bool e : v) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p);
template <class C> string to_string(C c) {
  string res = "{";
  for (auto e : c) res += to_string(e) + ", ";
  return res += "}";
}
template <class T, class U> string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug() { cerr << '\n'; }
template <class Head, class... Tail> void debug(Head head, Tail... tail) {
  cerr << '\t' << to_string(head), debug(tail...);
}
#ifdef LOCAL
#define print(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define print(...)
#endif

vector<ll> v;
ll max_d = 0;
int n, k;
ll ans = 0;
bool isNotZero = false;

void dfs(bool start, int d){
	if(d == -1)  return;
	int num  =0;
	vector<ll> v2;
	rep(i, v.size()){
		if(v[i] >> d & 1) {
			num++;
			v2.push_back(v[i]);
		}
	}
	if(num >= k){
		isNotZero = true;
		v = v2;
	}
	bool nS = start | num >= k;
	dfs(nS, d-1);
}

int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

	cin >> n >> k;
	vector<ll> a(n), h(n+1);
	rep(i, n) {
		cin >> a[i];
		h[i+1]  = h[i] + a[i];
	}

	rep2(i, 0, n+1){
		rep2(j, i+1, n+1){
			ll tmp = h[j] - h[i];
			v.push_back(tmp);
			ll d = 0;
			while(tmp > 0){
				tmp >>= 1;
				d++;
			}
			chmax(max_d, d);
		}
	}
	// print(max_d);

	dfs(false, 50);
	if(!isNotZero){
		cout << 0 << endl;
		return 0;
	}
	ans = v[0];
	rep(i, k){
		ans &= v[i];
	}

	cout << ans << endl;

	return 0;
}
