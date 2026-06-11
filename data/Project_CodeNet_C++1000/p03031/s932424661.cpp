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
#define output(x) do{cout<<x;return 0;}while(0)  // cout return
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
	/*** Bit操作ライブラリ ***/

	struct NyaaBit
	{

		/**
		@brief 任意桁でビットが1になっている数を返す関数
		@note
		 結果はNyaBit::Test()と同じ。
		**/
		static long long Count(long long x, long long i)
		{
			return Test(x, i);
		}

		/**
		@brief 任意桁でビットが1になっている数を返す関数
		@note
		 結果はBit::Test()と同じ。
		 flipがtrueならビットが0になっている数を返す。
		**/
		static long long Count(long long x, long long i, bool flip)
		{
			return Test(x, i, flip);
		}

		/**
		@brief コンテナ各要素の任意桁でビットが1になっている数を返す関数
		@note
		 コンテナ半開区間[b, e)で各要素i桁目ビットが1になっている数を返す。
		 sumは初期値で通常デフォルト引数のままで良い。
		**/
		template <class T> static long long EachCount(T b, T e, long long i, long long sum = 0)
		{
			for (auto it = b; it != e; ++it) sum += Test(*it, i);
			return sum;
		}

		/**
		@brief コンテナ各要素の任意桁でビットが1になっている数を返す関数
		@note
		 コンテナ半開区間[b, e)で各要素i桁目ビットが1になっている数を返す。
		 flipをtrueにするとビットが0になっている数を返す。
		 sumは初期値で通常デフォルト引数のままで良い。
		**/
		template <class T> static long long EachCount(T b, T e, long long i, bool flip, long long sum = 0)
		{
			for (auto it = b; it != e; ++it) sum += Test(*it, i, flip);
			return sum;
		}

		/**
		@brief 任意範囲でビットが1になっている数を返す関数
		@note
		 値xの半開区間[b, e)でビットが1になっている数を返す。
		 flipをtrueにするとビットが0になっている数を返す。
		 **/
		static long long RangeCount(long long x, long long b, long long e, long long sum = 0)
		{
			for (auto i = b; i < e; i++) sum += Test(x, i);
			return sum;
		}

		/**
		@brief 任意範囲でビットが1になっている数を返す関数
		@note
		 値xの半開区間[b, e)でビットが1になっている数を返す。
		 flipをtrueにするとビットが0になっている数を返す。
		 **/
		static long long RangeCount(long long x, long long b, long long e, bool flip, long long sum = 0)
		{
			for (auto i = b; i < e; i++) sum += Test(x, i);
			return sum;
		}

		/**
		@brief ビットシフトした結果を返す関数
		@note
		 値xをnビット左シフトした結果を10進数で返す。
		**/
		static long long Shift(long long x, long long n)
		{
			return (x << n);
		}

		/**
		@brief サイズを返す関数
		@note
		 値xのサイズを返す。
		**/
		static long long Size(long long x, long long size = 0)
		{
			while ((long long)pow(2, size) <= x) size++;
			return size;
		}

		/**
		@brief 任意桁のビットを返す関数
		@note
		 値xのi桁目ビットを返す。
		**/
		static long long Test(long long x, long long i)
		{
			return ((x & Shift(1, i)) != 0) ? 1 : 0;
		}

		/**
		@brief 任意桁のビットを返す関数
		@note
		 値xのi桁目ビットを返す。
		 flipがtrueなら反転したビットを返す。
		**/
		static long long Test(long long x, long long i, bool flip)
		{
			if (flip)
				return ((x & Shift(1, i)) != 0) ? 0 : 1;
			else
				return ((x & Shift(1, i)) != 0) ? 1 : 0;
		}

		/**
		@brief 任意桁のビットを10進数に変換して返す
		@note
		 値xのi桁目ビットを10進数に変換して返す。
		**/
		static long long To10(long long x, long long i)
		{
			return Test(x, i) * (long long)pow(2, i);
		}

		/**
		@brief ビット組み合わせテーブル
		@note
		 サイズN桁ビットでm個が1となるビット列の集合を返す。
		**/
		static void CombinationTable(long long N, long long m, vector<long long>& res)
		{
			if (N <= 0 || m < 0) return;

			long long c = (1LL << m) - 1;
			while (c < 1LL << N)
			{
				res.push_back(c);
				long long x = c & -c, y = c + x;
				c = ((c) & ~y) / x >> 1LL | y;
			}
		}
	};
}


/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = NT_ModLL< 1000000007 >;
//using mll = NT_ModLL< 998244353 >;

int main(void)
{
	ll N, M; cin >> N >> M;
	vvt <bool> s; MakeVVT(M, N, s, false);
	rep(i, 0, M)
	{
		ll k; cin >> k;
		rep(j, 0, k)
		{
			ll nyaa; cin >> nyaa; nyaa--;
			s[i][nyaa] = true;
		}
	}
	vt<ll> p(M); each(i, e, p) cin >> e;

	ll ans = 0;
	rep(i, 0, Pow2(N))
	{
		rep(j, 0, M)
		{
			ll count = 0;
			each(k, e, s[j])
			{
				if (e == true && NyaaBit::Test(i, k) == 1) count++;
			}
			if (count % 2 != p[j]) break;
			if (j == M-1) ans++;
		}
	}

	cout << ans;
	return 0;
}