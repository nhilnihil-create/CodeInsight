#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
	#include <boost/multiprecision/cpp_int.hpp>
	#include <boost/multiprecision/cpp_dec_float.hpp>
	using bll = boost::multiprecision::cpp_int;
	using bdouble = boost::multiprecision::cpp_dec_float_100;
#endif
#ifdef LOCAL_DEV
	void debug_impl() { std::cerr << std::endl; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) std::cerr << std::boolalpha << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); std::cerr << std::noboolalpha;
#else
	#define debug(...)
#endif
#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE
	#include <boost/stacktrace.hpp>
	template<typename T> class dvector : public std::vector<T> {
	public:
		dvector() : std::vector<T>() {}
		explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
		dvector(const std::vector<T>& v) : std::vector<T>(v) {}
		dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
		dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
		dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
		T& operator[](size_t n) {
			try { return this->at(n); } catch (const std::exception& e) {
				std::cerr << boost::stacktrace::stacktrace() << std::endl; return this->at(n);
			}
		}
		const T& operator[](size_t n) const {
			try { return this->at(n); } catch (const std::exception& e) {
				std::cerr << boost::stacktrace::stacktrace() << std::endl; return this->at(n);
			}
		}
	};
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		dbool(const dbool &b) : boolvalue(b.boolvalue) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector<T>& v) {
		for (int i = 0, len = v.size(); i < len; ++i){ s << v[i]; if (i < len - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector< dvector<T> >& vv) {
		for (int i = 0, len = vv.size(); i < len; ++i){ s << vv[i] << std::endl; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{" << std::endl; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << std::endl; } s << "}" << std::endl; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) { 
		return s << "(" << p.first << ", " << p.second << ")"; }
	#define vector dvector
	#define bool dbool
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE(int e) { std::cerr << boost::stacktrace::stacktrace() << std::endl; throw SIGFPE_exception();	}
	void catch_SIGSEGV(int e) { std::cerr << boost::stacktrace::stacktrace() << std::endl; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main(){ signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
#endif
//#define int long long
using ll = long long;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
#define p(var) std::cout<<var<<std::endl
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
template<typename T> inline void pv(vector<T> &v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

/*-----8<-----template-----8<-----*/

class Edge {
public:
	ll from,to,cost;
	Edge() {}
	Edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {}
};
ostream& operator<<(ostream& s, const Edge& e) {
	s << "{ " << e.from << " -> " << e.to << ", " << e.cost << " }";
	return s;
}

/*
引数
　g:探索するグラフ
　start:探索するスタートノード番号
戻り値
　dist:スタートノードから各頂点までの距離
　prev:最短路木の親頂点
*/
void dijkstra(const vector<vector<Edge>> &g, ll start, vector<ll> &dist, vector<ll> &prev) {
	ll gsize = g.size();
	dist.assign(gsize, INF); dist[start] = 0;
	prev.assign(gsize, -1);

	priority_queue<Edge, vector<Edge>, function<bool(Edge,Edge)>> que(
		[](const Edge &x, const Edge &y){
			return x.cost != y.cost ? (x.cost > y.cost) : 
				(x.from != y.from ? x.from < y.from : x.to < y.to);
		}
	);
	que.push(Edge(-1, start, 0));
	while (!que.empty()) {
		Edge e = que.top();
		que.pop();
		if (prev[e.to] != -1) continue;
		prev[e.to] = e.from;
		for(Edge f : g[e.to]) {
			if (dist[f.to] > e.cost + f.cost) {
				dist[f.to] = e.cost + f.cost;
				que.push(Edge(f.from, f.to, e.cost+f.cost));
			}
		}
	}
}
//最短路木の親頂点を元にstart->goalの経路を作成
vector<ll> buildPath(const vector<ll> &prev, ll goal) {
	vector<ll> path;
	for (ll u = goal; u >= 0; u = prev[u])
		path.push_back(u);
	reverse(path.begin(), path.end());
	return path;
}
/*-----8<-----library-----8<-----*/

const ll K_MAX = 1e5;

ll K;

void solve() {
	scanf("%lld", &K);

	vector<vector<Edge>> g(K);
	rep(i,K-1){
		Edge e(i,i+1,1);
		g[e.from].push_back(e);
	}
	Edge e(K-1,0,1);
	g[e.from].push_back(e);

	repeq(i,K-1){
		ll t=(10*i)%K;
		if(i==t)continue;
		Edge e(i,t,0);
		g[e.from].push_back(e);
	}
	debug(g);
	vector<ll> dist, prev;
	dijkstra(g, 1, dist, prev);
	debug(dist);
	
	printf("%lld\n", 1+dist[0]);
}

// https://atcoder.jp/contests/abc077/tasks/arc084_b
signed main() {
	solve();
	return 0;
}
