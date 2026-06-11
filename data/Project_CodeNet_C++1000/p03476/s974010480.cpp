#pragma GCC diagnostic ignored "-Wunused-variable" 
#include <bits/stdc++.h>
using namespace std;

#define BOOST
#ifdef BOOST
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/range/adaptor/reversed.hpp>
using namespace boost;
using ml = boost::multiprecision::cpp_int;
using md = boost::multiprecision::cpp_dec_float_100;
#define forir(i, ...) if(ll i=(ll)v.size())for(__VA_ARGS__)if(i--,1)
#define eachr(i, e, c) forir(i, auto &&e: adaptors::reverse(c))
#endif

/***** type *****/
using ll = long long;
using ld = long double;
using pll = pair<long long, long long>;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define coutd cout << fixed << setprecision(10)  // cout double
#define output(x) do{cout<<x<<endl;exit(0);}while(0)
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define fori(i, ...) if (ll i = -1) for(__VA_ARGS__) if (i++, 1)
#define each(i, e, c) fori (i, auto&& e: c)      // for each
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define pi 3.1415926535897932                    // 3.14 ...
/***** lambda *****/
auto Ceil = [] // if (a % b != 0) return a / b + 1;
(auto x) { return (ll)ceil(x); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoL = [] // char to number
(auto c) { return (ll)c - (ll)'0'; };
auto LtoC = [] // number to char
(auto n) { return (char)('0' + n); };
auto Pow = [] // long long pow
(auto a, auto b) { return (ll)pow(a, b); };
auto Pow2 = [] // long long pow2
(auto n) { return (1LL << n); };
auto Pow10 = [] // long long pow10
(auto n) { return (ll)pow(10, n); };
auto Size = []  // long long collection size
(auto& c) { return (ll)(c).size(); };
auto Sum = [] // long long accumulate
(auto b, auto e) { return accumulate(b, e, 0LL); };

/***** template *****/
template <class T> void MakeVVT
(ll ys, ll xs, vvt<T>& v, T fill = T())
{	// vector<vector<T>> resize + fill
	v.resize(ys); rep(y, 0, ys) v[y].resize(xs, fill);
}
template <class T> void MakeVVVT
(ll zs, ll ys, ll xs, vvvt<T>& v, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	v.resize(zs); rep(z, 0, zs) MakeVVT(ys, xs, v[z], fill);
}
template <class T> void InputVT
(ll xs, vt<T>& v, T fix = T())
{	// input vector<T> (T != struct) + fix
	v.resize(xs); rep(i, 0, xs) { cin >> v[i]; v[i] += fix; }
}
template <class T> void InputVVT
(ll ys, ll xs, vvt<T>& v, T fix = T())
{	// input vector<vector<T>> (T != struct) + fix
	MakeVVT(ys, xs, v, fix);
	rep(y, 0, ys) rep(x, 0, xs) { cin >> v[y][x]; v[y][x] += fix; }
}
template <class T> void InputVVVT
(ll zs, ll ys, ll xs, vvvt<T>& v, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	v.resize(zs); rep(z, 0, zs) InputVVT(ys, xs, v[z], fix);
}

/**************************************/
/********** BEGIN OF NYA LIB **********/
/**************************************/

namespace NyaGadget {}

namespace NyaGadget
{
	/***** 素数テーブルライブラリ *****/

	void PrimeTable(long long n, std::vector<long long>& res)
	{
		std::vector<bool> test(n + 1, true);
		test[0] = test[1] = false;
		for (auto i = 2LL; i * i <= n; i++)
		{
			if (!test[i]) continue;
			for (long long j = 2 * i; j <= n; j += i) test[j] = false;
		}
		res.clear();
		for (auto i = 0LL; i < (long long)test.size(); i++)
		{
			if (test[i]) res.push_back(i);
		}
	}

	void PrimeTable(long long n, std::vector<bool>& res)
	{
		res.resize(n + 1, true);
		res[0] = res[1] = false;
		for (auto i = 2LL; i * i <= n; i++)
		{
			if (!res[i]) continue;
			for (auto j = 2LL * i; j <= n; j += i) res[j] = false;
		}
	}
}

namespace NyaGadget
{
	/***** 累積和ライブラリ *****/

	template <class T> struct DS_NyaaCumulativeSum
	{
		std::vector<T> sum;
		DS_NyaaCumulativeSum(std::vector<T>& v)
		{
			if (v.empty()) sum.push_back(0);
			else sum.push_back(v.front());
			for (long long i = 1; i < (long long)v.size(); ++i) sum.push_back(sum.back() + v[i]);
		}
		/**
		@brief 範囲の合計値を取得する
		@note
		 閉区間[s, t)の合計値を返す。
		 範囲外のsやtに対しては0を返す。
		**/
		T Range(long long s, long long t)
		{
			if (s < 0) s = 0;
			if ((long long)sum.size() < t) t = (long long)sum.size();
			// 戻り値の計算
			if (t <= 0 || (long long)sum.size() <= s) return 0;
			return (s == 0) ? sum[t - 1] : sum[t - 1] - sum[s - 1];
		}
	};
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = ModLL< 1000000007 >;
//using mll = ModLL< 998244353 >;

int main(void)
{
	ll Q; cin >> Q;
	vt<pll> range(Q); each(i, e, range) cin >> e.first >> e.second;

	vt<bool> res;
	PrimeTable(Pow10(5)+1, res);
	vt<ll> test(Pow10(5) + 2);
	rep(i, 1, Pow10(5) + 1) if (res[i] && res[(i + 1) / 2]) test[i] = 1;
	DS_NyaaCumulativeSum cs(test);

	each(i, e, range) cout << cs.Range(e.first, e.second+1) << endl;
	return 0;
}
