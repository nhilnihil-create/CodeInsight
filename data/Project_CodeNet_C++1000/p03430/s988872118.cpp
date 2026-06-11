#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
	#include <boost/multiprecision/cpp_int.hpp>
	#include <boost/multiprecision/cpp_dec_float.hpp>
	using bll = boost::multiprecision::cpp_int;
	using bdouble = boost::multiprecision::cpp_dec_float_100;
#endif
#ifdef LOCAL_DEV
	void debug_impl() { std::cerr << '\n'; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)
#else
	#define debug(...) do {} while (false)
#endif
#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE
	#include <boost/stacktrace.hpp>
	namespace std {
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
					std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n);
				}
			}
			const T& operator[](size_t n) const {
				try { return this->at(n); } catch (const std::exception& e) {
					std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n);
				}
			}
		};
	}
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		dbool(const dbool& b) : boolvalue(b.boolvalue) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::dvector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::dvector<std::dvector<T>>& vv) {
		s << "\n"; for (size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template <typename T, size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
		s << "{ "; for (size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {
		return s << "(" << p.first << ", " << p.second << ")"; }
	#define vector dvector
	#define bool dbool
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE(int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception();	}
	void catch_SIGSEGV(int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
#endif
//#define int long long
using ll = long long;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = 998244353;//(ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1LL, 0LL, -1LL, 0LL};
constexpr ll dy[4] = {0LL, 1LL, 0LL, -1LL};
constexpr ll dx8[8] = {1LL, 0LL, -1LL, 0LL, 1LL, 1LL, -1LL, -1LL};
constexpr ll dy8[8] = {0LL, 1LL, 0LL, -1LL, 1LL, -1LL, 1LL, -1LL};
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define rrep(i, n)   for(ll i=(n)-1; i>=0; --i)
#define rrepeq(i, n) for(ll i=(n)  ; i>=1; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(std::vector<T>& v) { v.erase(std::unique(v.begin(), v.end()), v.end()); }

/*-----8<-----template-----8<-----*/
namespace makevectordetail {
	template <typename Tp, size_t N>
	std::vector<Tp> make_vector(
			std::vector<size_t>& sizes,
			typename std::enable_if<(N == 1), Tp const&>::type x
	) {
		return std::vector<Tp>(sizes[0], x);
	}
	template <typename Tp, size_t N>
	auto make_vector(
			std::vector<size_t>& sizes,
			typename std::enable_if<(N > 1), Tp const&>::type x
	) {
		size_t size = sizes[N-1];
		sizes.pop_back();
		return std::vector<decltype(make_vector<Tp, N-1>(sizes, x))>(
				size, make_vector<Tp, N-1>(sizes, x)
		);
	}
}
template <typename Tp, typename sizetype, size_t N>
auto make_vector(sizetype const(&sizes)[N], Tp const& x = Tp()) {
	std::vector<size_t> s(N);
	for (size_t i = 0; i < N; ++i) s[i] = sizes[N-i-1];
	return makevectordetail::make_vector<Tp, N>(s, x);
}
//vector<vector<vector<ll>>> v = make_vector<ll>({1, 2, 3}, 0LL);
/*-----8<-----library-----8<-----*/

string S;
ll K;
//dp[l][r][k] 文字変更をk回行った状態で[l,r]間の回文の最大長
vector<vector<vector<ll>>> dp;
ll f(ll l,ll r,ll k){
	if(dp[l][r][k])return dp[l][r][k];
	//1文字
	if(l==r)return dp[l][r][k]=1;
	//2文字
	if(r-l==1){
		//元から同じ || 変更して同じにした
		if(S[l]==S[r] || k<K)return dp[l][r][k]=2;
		return dp[l][r][k]=1;
	}

	ll ans=0;
	//左右に関係ない文字を追加しても回文長は同じ
	chmax(ans, f(l+1,r,k));
	chmax(ans, f(l,r-1,k));

	if(S[l]==S[r]){
		//文字が同じ → 回文長に2加算
		chmax(ans, f(l+1,r-1,k)+2);
	}else if(k<K){
		//文字変更して無理矢理一緒にする
		chmax(ans, f(l+1,r-1,k+1)+2);
	}

	return dp[l][r][k]=ans;
}

void solve() {
	
	cin>>S>>K;
	dp = make_vector<ll>({S.size()+1, S.size()+1, (size_t)K+1}, 0);

	f(0, S.size()-1, 0);
	ll ans=0;
	rep(i,K+1)chmax(ans, dp[0][S.size()-1][i]);
	p(ans);
}

signed main() {
	solve();
	return 0;
}
