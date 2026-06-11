#define _USE_MATH_DEFINES
#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <nmmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>

using namespace std;

#define dprint(Exp,...) if(Exp){fprintf(stderr, __VA_ARGS__);}
#define printe(...) fprintf(stderr, __VA_ARGS__);
#define PrtExp(_Exp)  cerr<< #_Exp <<" = "<< (_Exp)
#define PrtExpN(_Exp)  cerr<< #_Exp <<" = "<< (_Exp) <<"\n"

#define SINT(n) scanf("%d",&n)
#define SINT2(n,m) scanf("%d %d",&n,&m)
#define SINT3(n,m,o) scanf("%d %d %d",&n,&m,&o)
#define SINT4(n,m,o,P) scanf("%d %d %d %d",&n,&m,&o,&P)
#define SINT5(n,m,o,P,q) scanf("%d %d %d %d %d",&n,&m,&o,&P,&q)
#define SLL(n) scanf("%lld",&n)
#define SLL2(n,m) scanf("%lld %lld",&n,&m)
#define SLL3(n,m,o) scanf("%lld %lld %lld",&n,&m,&o)
#define SST(s) scanf("%s",s)
#define SCH(c) scanf("%c",&c)

#define GC() getchar()

#define PINT(n) printf("%d",(int)(n))
#define PINT2(n,m) printf("%d %d",(int)(n),(int)(m))
#define PINT3(n,m,l) printf("%d %d %d",(int)(n),(int)(m),(int)(l))
#define PLL(n) printf("%lld",(long long)(n))
#define PST(s) printf("%s",(s))
#define PCH(s) printf("%c",(s))

#define PINTN(n) printf("%d\n",(int)(n))
#define PINT2N(n,m) printf("%d %d\n",(int)(n),(int)(m))
#define PINT3N(n,m,l) printf("%d %d %d\n",(int)(n),(int)(m),(int)(l))
#define PLLN(n) printf("%lld\n",(long long)(n))
#define PSTN(s) printf("%s\n",(s))
#define PCHN(s) printf("%c\n",(s))

#define PSP() printf(" ")
#define PN() printf("\n")

#define PC(c) putchar(c)
#define CSP (' ')
#define SN ("\n")

#define rep(i,a) for(int i=0;i<a;i++)
#define reP(i,a) for(int i=0;i<=a;i++)
#define Rep(i,a) for(int i=a-1;i>=0;i--)
#define ReP(i,a) for(int i=a;i>=0;i--)

#define rEp(i,a) for(i=0;i<a;i++)
#define rEP(i,a) for(i=0;i<=a;i++)
#define REp(i,a) for(i=a-1;i>=0;i--)
#define REP(i,a) for(i=a;i>=0;i--)

#define repft(i,a,b) for(int i=a;i<b;i++)
#define repfT(i,a,b) for(int i=a;i<=b;i++)
#define Repft(i,a,b) for(int i=a-1;i>=b;i--)
#define RepfT(i,a,b) for(int i=a;i>=b;i--)

#define foreach(a,it) for(auto it = a.begin(); it != a.end(); ++it)

#define FILL(a,v) fill(begin(a),end(a), v)
#define FILL0(a) memset(a,0,sizeof(a))
#define FILL1(a) memset(a,-1,sizeof(a))

typedef long long ll;

typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll>   Pll;


const int INF = 1'010'000'000; // 0x3C33'6080
const ll INFLL = 0x1f1f1f1f1f1f1f1fLL;//2,242,545,357,980,376,863

template <class A, class B> inline ostream& operator<<(ostream& st, const pair<A, B>& P) { return st << "(" << P.first << "," << P.second << ")"; };
template <class A, class B> inline pair<A, B> operator+(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first + Q.first, P.second + Q.second); };
template <class A, class B> inline pair<A, B> operator-(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first - Q.first, P.second - Q.second); };

#define fs  first
#define sc  second


template <typename monoid>
struct segment_tree {
	using M = monoid;
	using T = typename M::value_type;

	std::size_t sz;
	std::vector<T> x;

	segment_tree(std::size_t n = 0) {
		sz = 1;
		while (sz < n) sz *= 2;
		x.assign(sz * 2, M::id());
		initialize();
	}

	template <typename iterator>
	segment_tree(iterator first, iterator last) {
		sz = 1;
		std::size_t n = std::distance(first, last);
		while (sz < n) sz *= 2;
		x.assign(sz * 2, M::id());
		std::copy(first, last, x.begin() + sz);
		initialize();
	}

	void fill(const T &val) {
		std::fill(x.begin() + sz, x.end(), val);
		initialize();
	}

	void initialize() {
		for (int i = (int)sz - 1; i >= 1; --i) {
			x[i] = M::op(x[i * 2 + 0], x[i * 2 + 1]);
		}
	}

	T accumulate(std::size_t l, std::size_t r) const {
		T al = M::id(), ar = M::id();
		for (l += sz, r += sz; l < r; l /= 2, r /= 2) {
			if (l & 1) al = M::op(al, x[l++]);
			if (r & 1) ar = M::op(x[--r], ar);
		}
		return M::op(al, ar);
	}

	void update(std::size_t i, const T &val) {
		x[i += sz] = val;
		while (i > 1) {
			x[i / 2] = M::op(x[i], x[i ^ 1]);
			i /= 2;
		}
	}

	T operator[](std::size_t i) const { return x[sz + i]; }
};


template <typename T>
struct max_monoid {
	using value_type = T;
	static constexpr value_type id() { return std::numeric_limits<value_type>::min(); }
	static value_type op(const value_type &a, const value_type &b) { return std::max(a, b); }
};

ll x[100005];
ll v[100005];

Pll L[100005];
Pll R[100005];

int main() {
	ll n, c;
	cin >> n >> c;
	rep(i, n) {
		cin >> x[i] >> v[i];
	}

	/*
	segment_tree<max_monoid<ll>> L(n), R(n);

	L.fill(0);
	R.fill(0);
	*/

	{
		ll su = 0;
		ll pre = 0;
		Pll ma = { 0 ,0 };
		rep(i, n) {
			ll w = v[i] - (x[i] - pre);
			su += w;
			//R.update(i, su);
			ma = R[i] = max(ma, { su, -x[i] });
			pre = x[i];
			//printf("R[%d] %lld(%lld)\n", i, R[i].first, R[i].second);
		}
	}
	{
		ll su = 0;
		ll pre = c;
		Pll ma = { 0 , 0 };
		Rep(i, n) {
			ll w = v[i] - (pre - x[i]);
			su += w;
			//L.update(i, su);
			ma = L[i] = max(ma, { su, -(c - x[i]) });
			pre = x[i];
			//printf("L[%d] %lld(%lld)\n", i, L[i].first, L[i].second);
		}
	}
	//cerr << endl;

	ll ret = 0;

	ret = max(L[0].first, R[n-1].first);
	//cout << L[n - 1] << "  " << R[0] << endl;

	repft(i, 0, n-1) {
		/*
		ll l = max(0LL, L.accumulate(0, i));
		ll r = max(0LL, R.accumulate(i, n));
		*/
		ll r = R[i].first;
		ll l = L[i+1].first;


		ret = max(ret, r);
		ret = max(ret, l);

		//cerr << r << " " << l;

		//ll lr = r + l - min(x[i], c - x[i + 1]);
		ll lr = r + l + max(R[i].second, L[i+1].second);

		ret = max(ret, lr);
		//cerr << " " << lr;

		//cerr << endl;
	}
	cout << ret << endl;


}
