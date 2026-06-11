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
#endif
//#define int long long
using ll = long long;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr int dx[4]={1,0,-1,0};
constexpr int dy[4]={0,1,0,-1};
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
template< typename Monoid >
class SegmentTree {
public:
	using F = function< Monoid(Monoid, Monoid) >;

	ll sz;
	vector< Monoid > seg;

	const F f;
	const Monoid M1;

	SegmentTree(ll n, const F f, const Monoid &M1) : f(f), M1(M1) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2 * sz, M1);
	}

	void set(ll k, const Monoid &x) {
		seg[k + sz] = x;
	}

	void build() {
		for(ll k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	void update(ll k, const Monoid &x) {
		k += sz;
		seg[k] = x;
		while(k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	Monoid query(ll a, ll b) {
		Monoid L = M1, R = M1;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) L = f(L, seg[a++]);
			if(b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	Monoid operator[](const ll &k) const {
		return seg[k + sz];
	}

	template< typename C >
	ll find_subtree(ll a, const C &check, Monoid &M, bool type) {
		while(a < sz) {
			Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
			if(check(nxt)) a = 2 * a + type;
			else M = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}

	template< typename C >
	ll find_first(ll a, const C &check) {
		Monoid L = M1;
		if(a <= 0) {
			if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
			return -1;
		}
		ll b = sz;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) {
				Monoid nxt = f(L, seg[a]);
				if(check(nxt)) return find_subtree(a, check, L, false);
				L = nxt;
				++a;
			}
		}
		return -1;
	}

	template< typename C >
	ll find_last(ll b, const C &check) {
		Monoid R = M1;
		if(b >= sz) {
			if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
			return -1;
		}
		ll a = sz;
		for(b += sz; a < b; a >>= 1, b >>= 1) {
			if(b & 1) {
				Monoid nxt = f(seg[--b], R);
				if(check(nxt)) return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}
};

/*-----8<-----library-----8<-----*/

const ll N_MAX = 1e6;
const ll Q_MAX = 75;

ll N;
string S;
ll Q;
vector<ll> k;

void solve() {
	scanf("%lld", &N);
	cin >> S;
	scanf("%lld", &Q);
	k.assign(Q, 0);
	rep(i, Q) scanf("%lld", &k[i]);
/*
	auto addlambda = [](ll x,ll y){return x+y;};
	SegmentTree<ll> dseg(1e6+1, addlambda, 0LL);
	SegmentTree<ll> cseg(1e6+1, addlambda, 0LL);
	vector<ll> dindex,mindex;
	rep(i,S.size()){
		if(S[i]=='D'){dseg.set(i,1);dindex.push_back(i);}
		if(S[i]=='C')cseg.set(i,1);
		if(S[i]=='M')mindex.push_back(i);
	}
	dseg.build();cseg.build();
	debug(dindex);
	debug(mindex);
*/
	vector<ll> anslist;
	rep(q,Q){
		ll ans = 0;
		ll d=0,m=0,dm=0;
		rep(i,S.size()){
			ll j=i-k[q];
			if(j>=0 && S[j]=='D'){
				d--;
				if(dm>0)dm-=m;
			}else if(j>=0 && S[j]=='M'){
				m--;
			}else if(j>=0 && S[j]=='C'){
				
			}

			if(S[i]=='D'){
				d++;
			}else if(S[i]=='M'){
				m++;
				dm+=d;
			}else if(S[i]=='C'){
				ans+=dm;
			}
			debug(S[i],d,m,dm,ans);
			if(j>=0){debug(S[j]);}
		}
		anslist.push_back(ans);
	}
	rep(i,Q)p(anslist[i]);
}

// https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_c
signed main() {
	solve();
	return 0;
}
