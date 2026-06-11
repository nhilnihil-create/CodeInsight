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

int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

	int N; cin >> N;

	if(N == 3){
		cout << 2 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 2 << " " << 3 << endl;
		return 0;
	}

	vector<pair<int, int> > ans;

	int NN = N - N % 2;

	vector<pair<int, int> > g;
	rep(i, NN / 2){
		g.push_back({i, NN - i - 1});
	}
	rep(i, g.size()){
		rep2(j, i+1, g.size()){
			auto a = g[i];
			auto b = g[j];
			ans.push_back({a.first, b.first});
			ans.push_back({a.first, b.second});
			ans.push_back({a.second, b.first});
			ans.push_back({a.second, b.second});
		}
	}

	if(N % 2 == 1){
		rep(i, N-1){
			ans.push_back({N-1, i});
		}
	}

	cout << ans.size() << endl;
	rep(i, ans.size()){
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}


	return 0;
}
