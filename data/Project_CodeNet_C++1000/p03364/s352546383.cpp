#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace std;
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
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) { return s << "(" << p.first << ", " << p.second << ")"; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector<T>& v) {
		for (int i = 0, len = v.size(); i < len; ++i){ s << v[i]; if (i < len - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector< dvector<T> >& vv) {
		for (int i = 0, len = vv.size(); i < len; ++i){ s << vv[i] << std::endl; } return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{" << std::endl; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << std::endl; } s << "}" << std::endl; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}" << std::endl; return s; }
	#define vector dvector
	#define bool dbool
#endif
//#define int long long
using ll = long long;
using bll = boost::multiprecision::cpp_int;
using bdouble = boost::multiprecision::cpp_dec_float_100;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr int dx[4]={1,0,-1,0};
constexpr int dy[4]={0,1,0,-1};
#define p(var) std::cout<<var<<std::endl
#define PI (acos(-1))
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
template<typename T> inline void pv(vector<T> &v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T1, typename T2> inline T1 power(T1 x, T2 n){ return n ? power(x*x%MOD,n/2)*(n%2?x:1)%MOD : 1; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

/*-----8<-----8<-----*/


/*
RollingHash(s, mod, base):= 文字列 s のハッシュテーブルを構築する。
get(l, r):= 区間 [l,r) のハッシュ値を求める。
connect(h1, h2, h2len):= ハッシュ値 h1 と, 長さ h2len のハッシュ値 h2 を結合する。
LCP(b, l1, r1, l2, r2):= 区間 [l1,r1) と, ハッシュテーブルが b からなる区間 [l2,r2) の文字列の最長共通接頭辞の長さを求める。
*/
//using rh_type = boost::multiprecision::cpp_int;
using rh_type = unsigned long long;
class RollingHash {
public:
	rh_type mod;
	vector< rh_type > hashed, power;
 
	inline rh_type mul(rh_type a, rh_type b) const {
		return a * b % mod;
	}
 
	RollingHash(const string &s, rh_type mod = 1000000007, rh_type base = 10007) : mod(mod) {
		int sz = (int) s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;
		for(int i = 0; i < sz; i++) {
			power[i + 1] = mul(power[i], base);
			hashed[i + 1] = mul(hashed[i], base) + s[i];
			if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
		}
	}
 
	rh_type get(int l, int r) const {
		rh_type ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
		if(ret >= mod) ret -= mod;
		return ret;
	}
 
	rh_type connect(rh_type h1, int h2, int h2len) const {
		rh_type ret = mul(h1, power[h2len]) + h2;
		if(ret >= mod) ret -= mod;
		return ret;
	}
 
	int LCP(const RollingHash &b, int l1, int r1, int l2, int r2) {
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while(high - low > 1) {
			int mid = (low + high) / 2;
			if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
			else high = mid;
		}
		return (low);
	}
};


signed main() {
	ll N;
	cin>>N;
	vector<string> s(N*2);
	rep(i,N){
		cin>>s[i];
	}

	rep(i,N){
		s[i]+=s[i];
	}
	rep(i,N){
		s[i+N]=s[i];
	}

	vector<string> t=s;
	rep(i,2*N)rep(j,2*N){
		t[i][j]=s[j][i];
	}

	vector<RollingHash> yoko,tate;
	rep(i,2*N){
		RollingHash r(s[i]);
		yoko.push_back(r);
	}
	rep(i,2*N){
		RollingHash r(t[i]);
		tate.push_back(r);
	}
	debug(s);debug(t);


	ll ans=0;
	rep(j,N)rep(k,N){
		if([&]{
			rep(i,N){
				ll hash1 = yoko[i+k].get(j, j+N);
				ll hash2 = tate[i+j].get(k, k+N);
				debug(s[i+k].substr(j,N), t[i+j].substr(k,N));
				if(hash1!=hash2)return false;
			}
			return true;
		}()){
			ans++;
		}
		debug("-----------------");
	}	

	p(ans);

	return 0;
}

