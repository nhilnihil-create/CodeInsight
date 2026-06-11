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
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end())
void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(vector<T> &v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T> inline bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T &a, T b) { return a > b && (a = b, true); }

/*-----8<-----template-----8<-----*/

/*-----8<-----library-----8<-----*/

signed main() {
	ll N;
	cin>>N;
	vector<ll> a(N,0);
	rep(i,N)cin>>a[i];

	ll left = INF;
	ll right = 0;
	auto isOK = [&](ll val) -> bool {
		vector<pair<ll,ll>> c({{1,a[0]}});
		auto addc = [&](pair<ll,ll> x){
			if(c.size()>0&&c.back().first==x.first)c.back().second+=x.second;
			else c.push_back(x);
		};
		ll len=a[0];
		repeq(i,N-1){
			if(a[i-1]<a[i]){
				addc({1,a[i]-a[i-1]});
				len=a[i];
			}else{
				debug(len,c);
				while(a[i]<len){
					if(a[i] <= len-c.back().second){
						len-=c.back().second;
						c.pop_back();
					}else{
						c.back().second-=len-a[i];
						len=a[i];
					}
					debug(len,c);
				}

				//1足す
				if(c.size()==1 && c.back().first==val && c.back().second==a[i])return false;
				debug(c);
				if(c.back().first==val){
					pair<ll,ll> t2=c[c.size()-2];
					pair<ll,ll> t1=c[c.size()-1];
					c.pop_back();c.pop_back();
					if(t2.second>1){
						addc({t2.first, t2.second-1});
					}
					addc({t2.first+1, 1});
					addc({1, t1.second});
				}else{
					ll t=c.back().first+1;
					c.back().second--;
					if(c.back().second==0)c.pop_back();
					addc({t,1});
				}
			}
			debug(val,i,c);
		}
		return true;
	};
	while((ll)abs(right - left) > 1) {
		ll mid = left + (right - left) / 2;
		if(isOK(mid)) left = mid;
		else right = mid;
	}
	p(left);
	return 0;
}

