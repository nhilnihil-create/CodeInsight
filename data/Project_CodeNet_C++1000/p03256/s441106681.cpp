// need
#include <iostream>
#include <algorithm>

// data structure
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
//#include <deque>
#include <valarray>
#include <unordered_map>
#include <array>

// stream
//#include <istream>
//#include <sstream>
//#include <ostream>
#include <fstream>

// etc
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
//#include <chrono>
#include <random>
#include <numeric>

// input
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest&...rest) { std::cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC_ROW(type, n, ...)std::vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int w=0; w<n; ++w){MACRO_VEC_ROW_Scan(w, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest&...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { std::cin >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest&...rest) { std::cin >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& R:c)for(auto& w:R)std::cin>>w;

// output
#define OUT(dist) std::cout<<(dist);
#define FOUT(n, dist) std::cout<<std::fixed<<std::setprecision(n)<<(dist);
#define SOUT(n, c, dist) std::cout<<std::setw(n)<<std::setfill(c)<<(dist);
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define SHOW(dist) {std::cerr << #dist << "\t:" << (dist) << "\n";}
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t:";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}

// utility
#define ALL(a) (a).begin(),(a).end()
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define RFOR(w, a, n) for(int w=(n)-1;w>=(a);--w)
#define REP(w, n) for(int w=0;w<int(n);++w)
#define RREP(w, n) for(int w=int(n)-1;w>=0;--w)
#define FORLL(w, a, n) for(ll w=ll(a);w<ll(n);++w)
#define RFORLL(w, a, n) for(ll w=ll(n)-1;w>=ll(a);--w)
#define REPLL(w, n) for(ll w=0;w<ll(n);++w)
#define RREPLL(w, n) for(ll w=ll(n)-1;w>=0;--w)
#define IN(a, x, b) (a<=x && x<b)
template<class T> inline T CHMAX(T& a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }
#define EXCEPTION(msg) throw std::string("Exception : " msg " [ in ") + __func__ + " : " + std::to_string(__LINE__) + " lines ]"
#define TRY(cond, msg) try {if (cond) EXCEPTION(msg);}catch (std::string s) {std::cerr << s << std::endl;}
//void CHECKTIME(std::function<void()> f) { auto start = std::chrono::system_clock::now(); f(); auto end = std::chrono::system_clock::now(); auto res = std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count(); std::cerr << "[Time:" << res << "ns  (" << res / (1.0e9) << "s)]\n"; }

// test
template<class T> std::vector<std::vector<T>> VV(int n, int m, T init = T()) {
	return std::vector<std::vector<T>>(n, std::vector<T>(m, init));
}
template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PAIR = std::pair<int, int>;
using PAIRLL = std::pair<ll, ll>;
constexpr int INFINT = 1 << 30;                          // 1.07x10^ 9
constexpr int INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;                          // 1.15x10^18
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^18
constexpr double EPS = 1e-10;
constexpr int MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;

template<class T, size_t N> void FILL(T(&a)[N], const T& val) { for (auto& x : a) x = val; }
template<class ARY, size_t N, size_t M, class T> void FILL(ARY(&a)[N][M], const T& val) { for (auto& b : a) FILL(b, val); }
template<class T> void FILL(std::vector<T>& a, const T& val) { for (auto& x : a) x = val; }
template<class ARY, class T> void FILL(std::vector<std::vector<ARY>>& a, const T& val) { for (auto& b : a) FILL(b, val); }

// ------------>8------------------------------------->8------------

// use 'getDAG' after 'addEdge'.
// cmp : beforeV -> afterV ; v |-> cmp[v]
// pre : afterV ->{beforeV}; v |-> pre[v] (vector)
struct StronglyConnectedComponent {
	int n;
	std::vector<std::vector<int>> g, rg;
	std::vector<bool> used;
	std::vector<int> vs; // postorder
	std::vector<int> cmp; // topo-order
	std::vector<std::vector<int>> pre;

	StronglyConnectedComponent(int n) :
		n(n), g(n), rg(n), used(n), cmp(n) {}

	int operator[](int id) {
		return cmp[id];
	}

	void addEdge(int from, int to) {
		g[from].emplace_back(to);
		rg[to].emplace_back(from);
	}

	void dfs(int v) {
		used[v] = true;
		for (size_t i = 0; i < g[v].size(); ++i) {
			if (!used[g[v][i]]) dfs(g[v][i]);
		}
		vs.emplace_back(v);
	}

	void rdfs(int v, int k) {
		used[v] = true;
		cmp[v] = k;
		for (size_t i = 0; i < rg[v].size(); ++i) {
			if (!used[rg[v][i]]) rdfs(rg[v][i], k);
		}
	}

	int scc() {
		used.assign(n, false);
		vs.clear();
		for (size_t v = 0; v < n; ++v) {
			if (!used[v]) dfs(v);
		}

		used.assign(n, false);
		int k = 0;
		for (signed i = vs.size() - 1; i >= 0; --i) {
			if (!used[vs[i]]) rdfs(vs[i], k++);
		}

		return k;
	}

	bool same(int u, int v) {
		return cmp[u] == cmp[v];
	}

	std::vector<std::vector<int>> getDAG() {
		int N = scc();
		std::vector<std::vector<int>> res(N);
		std::vector<std::set<int>> set(N);
		pre.resize(N);
		REP(i, n) {
			set[cmp[i]].insert(i);
		}
		REP(i, N) {
			std::set<int> out;
			for (const auto& v : set[i]) {
				pre[i].emplace_back(v);
				for (const auto& to : g[v]) {
					out.insert(cmp[to]);
				}
			}
			for (const auto& to : out) {
				if (i != to) res[i].emplace_back(to);
			}
		}
		return res;
	}
};

signed main() {
	INIT;

	VAR(int, n, m);
	VAR(std::string, s);
	VEC_ROW(int, m, a, b);
	std::vector<bool> d(n);
	REP(i, n) d[i] = s[i] == 'A';

	std::vector<std::vector<int>> g(n);
	REP(i, m) {
		--a[i]; --b[i];
		g[a[i]].emplace_back(b[i]);
		g[b[i]].emplace_back(a[i]);
	}

	StronglyConnectedComponent G(n * 2);
	REP(i, n) {
		for (auto& x : g[i]) {
			if (s[i] == s[x]) G.addEdge(i + 0, x + n);
			if (s[i] != s[x]) G.addEdge(i + n, x + 0);
		}
	}

	auto GG = G.getDAG();
	OUT(GG.size() != n * 2 ? "Yes" : "No")BR;

	return 0;
}