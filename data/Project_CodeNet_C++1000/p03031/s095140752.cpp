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
	/***** Bit操作ライブラリ *****/

	struct NT_NyaaBit
	{
		/**
		@brief 1になっているビットの数を取得する
		@note flipをtrueにすると0になっているビットの数を返す。
		**/
		static long long Count(long long x, bool flip = false)
		{
			long long sum = 0;
			for (auto i = 0LL; i < Size(x); ++i) sum += Test(x, i, flip);
			return sum;
		}

		/**
		@brief bit列を整数に変換する
		**/
		static long long ToLL(std::string bit)
		{
			long long res = 0;
			long long maxSize = (long long)bit.size();
			for (auto i = 0LL; i < maxSize; ++i) if (bit[i] == '1') res += (1LL << (maxSize - i - 1));
			return res;
		}

		/**
		@brief 文字列に変換する
		**/
		static std::string ToString(long long x, bool flip = false)
		{
			std::string res;
			if (!flip) for (auto i = Size(x) - 1; -1 < i; --i) res += (char)('0' + Test(x, i));
			else       for (auto i = 0LL; i < Size(x); ++i)    res += (char)('0' + Test(x, i));
			return res;
		}

		/**
		@brief 文字列に変換する
		@note maxSize桁の文字列に変換する。
		**/
		static std::string ToString(long long maxSize, long long x, bool flip = false)
		{
			std::string res;
			for (auto i = 0LL; i < (maxSize - Size(x)); i++)   res += '0';
			if (!flip) for (auto i = Size(x) - 1; -1 < i; --i) res += (char)('0' + Test(x, i));
			else       for (auto i = 0LL; i < Size(x); ++i)    res += (char)('0' + Test(x, i));
			return res;
		}

		/**
		@brief 半開区間で1になっているビットの数を取得する
		@note
		値xの半開区間[b, e)でビットが1になっている数を返す。
		flipをtrueにすると0になっているビットの数を返す。
		**/
		static long long RangeCount(long long x, long long b, long long e, bool flip = false)
		{
			long long sum = 0;
			for (auto i = b; i < e; i++) sum += Test(x, i, flip);
			return sum;
		}

		/**
		@brief nビット左シフト
		**/
		static long long Shift(long long x, long long n)
		{
			return (x << n);
		}

		/**
		@brief 値xのビットサイズを取得する
		**/
		static long long Size(long long x)
		{
			long long size = 0;
			while ((long long)(1LL << size) <= x) size++;
			return size;
		}

		/**
		@brief 任意桁のビットを取得する
		@note flipがtrueなら反転したビット値を返す。
		**/
		static long long Test(long long x, long long i, bool flip = false)
		{
			if (flip) return ((x & Shift(1, i)) != 0) ? 0 : 1;
			else return ((x & Shift(1, i)) != 0) ? 1 : 0;
		}

		/**
		@brief 任意桁のビットを10進数に変換して返す
		@note 値xのi桁目ビットを10進数に変換して返す。
		**/
		static long long To10(long long x, long long i)
		{
			return Test(x, i) * (long long)pow(2, i);
		}

		/**
		@brief ビット組み合わせテーブル
		@note
		ビットサイズN桁でm個が1となるビット列の集合を昇順で返す。
		例えばN=4,m=2なら{0011, 0101, 0110, ... 1100}を返す。
		**/
		static void CombinationTable(long long N, long long m, std::vector<std::string>& res)
		{
			if (N <= 0 || m < 0) return;

			long long c = (1LL << m) - 1;
			while (c < 1LL << N)
			{
				res.push_back(ToString(N, c));
				long long x = c & -c, y = c + x;
				c = ((c) & ~y) / x >> 1LL | y;
			}
		}

		/**
		@brief ビット組み合わせテーブル
		@note
		ビットサイズN桁でm個が1となるビット列の集合を昇順で返す。
		例えばN=4,m=2なら{3(0011), 5(0101), 6(0110), ... 12(1100)}を返す。
		計算量は不明だが、素直な実装より高速に動作する。
		**/
		static void CombinationTable(long long N, long long m, std::vector<long long>& res)
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

	vvt<bool> s; MakeVVT(M, N, s);
	rep(i, 0, M)
	{
		ll k; cin >> k;
		rep(j, 0, k)
		{
			ll nyaa; cin >> nyaa; --nyaa;
			s[i][nyaa] = true;
		}
	}
	vt<ll> p(M); each(i, e, p) cin >> e;
	
	ll ans = 0;
	rep(i, 0, Pow2(N))
	{
		each(j, e, s)
		{
			ll count = 0;
			rep(k, 0, N)
			{	// ビットが0のときはカウントしてはいけない
				if (NT_NyaaBit::Test(i, k) == 1 && e[k]) ++count;
			}
			if (count % 2 != p[j]) break;
			if (j == Size(s) - 1) ++ans;
		}
	}
	cout << ans;
	return 0;
}
