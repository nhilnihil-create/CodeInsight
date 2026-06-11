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
	#define debug(...) { std::cerr << std::boolalpha << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); std::cerr << std::noboolalpha; }
#else
	#define debug(...) {}
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
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{" << std::endl; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << std::endl; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) { 
		return s << "(" << p.first << ", " << p.second << ")"; }
	#define vector dvector
	#define bool dbool
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE(int e) { std::cerr << boost::stacktrace::stacktrace() << std::endl; throw SIGFPE_exception();	}
	void catch_SIGSEGV(int e) { std::cerr << boost::stacktrace::stacktrace() << std::endl; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
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
constexpr int dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define rrep(i, n)   for(ll i=(n)-1; i>=0; --i)
#define rrepeq(i, n) for(ll i=(n)  ; i>=1; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(vector<T> &v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T> inline bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T &a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(vector<T> &v) { v.erase(unique(v.begin(), v.end()), v.end()); }

/*-----8<-----template-----8<-----*/

/*
直線/線分 ax+b の追加クエリと, ある点 x での最小値クエリを効率的に処理する。
add(a, b): f(x)=ax+b を追加
add(a, b, l, r): f(x)=ax+b (l≤x≤b) を追加
　小数なら add(a, b, l-eps, r+eps) で渡すようにしたほうがいいかもしれない
query(k): x=k での最小値を求める
*/
template < class T = long long, class Comp = less< T > >
class LiChaoTree {
public:
	static Comp comp;
	using Line = pair< T, T >;
	static inline T f(const Line &line, T x) { return line.first * x + line.second; }

	ll n;
	vector< Line > dat;
	vector< ll > used;
	vector< T > xs;
	void add(T a, T b) { add(0, n, Line(a, b)); }
	// [lx, rx]
	void add(T a, T b, T lx, T rx) {
		ll l = lower_bound(xs.begin(), xs.end(), lx) - xs.begin();
		ll r = upper_bound(xs.begin(), xs.end(), rx) - xs.begin();
		add(l, r, Line(a, b));
	}

private:
	// [l, r)
	void add(ll l, ll r, const Line &line) {
		ll l0 = l, r0 = r;
		ll sz = 1;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1, sz <<= 1) {
			if(l & 1) add(l, l0, l0 + sz, line), l0 += sz, l++;
			if(r & 1) --r, r0 -= sz, add(r, r0, r0 + sz, line);
		}
	}
	void add(ll k, ll l, ll r, Line line) {
		if(!used[k]) {
			used[k] = 1, dat[k] = line;
			return;
		}
		T ly = f(line, xs[l]), ry = f(line, xs[r - 1]);
		T nly = f(dat[k], xs[l]), nry = f(dat[k], xs[r - 1]);
		if(comp(nly, ly) && comp(nry, ry)) return;
		if(comp(ly, nly) && comp(ry, nry)) {
			dat[k] = line;
			return;
		}
		if(r - l == 1) return;
		ll m = (l + r) >> 1;
		if(comp(nly, ly)) swap(dat[k], line);
		if(comp(f(line, xs[m]), f(dat[k], xs[m]))) {
			swap(dat[k], line);
			add((k << 1) | 1, m, r, line);
		} else {
			add(k << 1, l, m, line);
		}
	}

public:
	void x(T x) { xs.emplace_back(x); }
	void prebuild() {
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		ll t = xs.size();
		n = 1;
		while(n < t) n <<= 1;
		xs.resize(n, xs.back());

		dat.resize(n << 1);
		used.resize(n << 1);
	}

	T query(T x) { return f(get(x), x); }

	Line get(T x) {
		ll i = lower_bound(xs.begin(), xs.end(), x) - xs.begin() + n;
		ll res = -1;
		for(; i > 0; i >>= 1)
			if(used[i])
				if(res == -1 || comp(f(dat[i], x), f(dat[res], x))) res = i;
		return dat[res];
	}
};

template < class T, class Comp >
Comp LiChaoTree< T, Comp >::comp;
/*-----8<-----library-----8<-----*/

void solve() {
	ll N;
	cin>>N;
	vector<double> t(N+2,0),v(N+2,0);
	repeq(i,N)cin>>t[i];
	repeq(i,N)cin>>v[i];

	double ans=0.;
	double vinit=0.;
	double vtmp=0.;
	//double timesum=0.5;
	repeq(i,N){
		repeq(j,t[i]*2){
			double x=0.5*j;
			double y1=x+vinit;

			vector<double> a;
			a.push_back(v[i]);
			a.push_back(y1);
			double tsum=0;
			for(ll k=i+1;k<=N+1;k++){
				tsum+=t[k-1];
				double y2=-(x-tsum)+v[k];
				a.push_back(y2);
			}
			debug(a);

			double minv=*min_element(all(a));
			double vsum=(vtmp+minv)*0.5*0.5;
			
			//debug(timesum,vtmp,minv,vsum);
			ans+=vsum;
			vtmp=minv;

			//timesum+=0.5;
		}
		vinit=vtmp;
	}
	cout.setf(ios::fixed), cout.precision(20);
	p(ans);
}

signed main() {
	solve();
	return 0;
}
