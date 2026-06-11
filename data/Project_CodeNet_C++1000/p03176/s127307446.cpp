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
#define eachr(i, e, c) forir(i, const auto &e: adaptors::reverse(c))
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
#define error(x) { cout << x; return 0; }        // cout error
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define fori(i, ...) if (ll i = -1) for(__VA_ARGS__) if (i++, 1)
#define each(i, e, c) fori (i, auto& e: c)       // for each
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define pi 3.1415926535897932                    // 3.14 ...
/***** lambda *****/
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoL = [] // char to number
(auto c) { return (ll)c - (ll)'0'; };
auto DivCeil = [] // if (a % b != 0) return a / b + 1;
(auto a, auto b) { return (ll)ceil((ld)a / (ld)b); };
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
	/***** セグメント木ライブラリ *****/
	// 点加算と区間最大値の取得

	template <class T> struct DS_SegmentTree
	{
		long long n;
		vector<T> node;

		/**
		@brief コンストラクタ
		@param size データ構造最大値
		@note
		 半開区間[0, size)のデータ構造を作る。
		**/
		DS_SegmentTree(long long size)
		{
			n = 1;
			while (n < size) n *= 2;
			node.resize(2 * n - 1, 0);
		}

		/**
		@brief コンストラクタ
		@param v 初期値
		@note
		 初期値を配列で渡して同じサイズのデータ構造を作る。
		**/
		DS_SegmentTree(vector<T> v)
		{
			n = 1;
			while (n < (long long)v.size()) n *= 2;
			node.resize(2 * n - 1, 0);
			for (long long i = 0; i < (long long)v.size(); i++) node[i + n - 1] = v[i];
			for (long long i = n - 2; i >= 0; i--) node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
		}

		/**
		@brief 点加算関数
		@note
		 要素[i]にxを加算する。
		**/
		void Add(long long i, T x)
		{
			i += (n - 1);
			node[i] = x;
			while (i > 0)
			{
				i = (i - 1) / 2;
				node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
			}
		}

		/**
		@brief 区間最大値取得関数
		@note
		 半開区間[li, ri)の最大値を取得する。
		**/
		T GetMax(long long li, long long ri, long long k = 0, long long l = 0, long long r = -1)
		{
			if (r < 0) r = n;
			if (r <= li || ri <= l) return 0;
			if (li <= l && r <= ri) return node[k];
			T vl = GetMax(li, ri, k * 2 + 1, l, (l + r) / 2);
			T vr = GetMax(li, ri, k * 2 + 2, (l + r) / 2, r);
			return max(vl, vr);
		}

		/**
		@brief 区間最小値取得関数
		@note
		 半開区間[li, ri)の最大値を取得する。
		**/
		T GetMin(int li, int ri, int k = 0, int l = 0, int r = -1)
		{
			// 最初に呼び出されたときの対象区間は [0, n)
			if (r < 0) r = n;
			// 要求区間と対象区間が交わらない -> 適当に返す
			if (r <= li || ri <= l) return -1;
			// 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
			if (li <= l && r <= ri) return node[k];

			// 要求区間が対象区間の一部を被覆 -> 子について探索を行う
			// 左側の子を vl ・ 右側の子を vr としている
			// 新しい対象区間は、現在の対象区間を半分に割ったもの
			int vl = GetMin(li, ri, 2 * k + 1, l, (l + r) / 2);
			int vr = GetMin(li, ri, 2 * k + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	};
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = NT_ModLL< 1000000007 >;
//using mll = NT_ModLL< 998244353 >;

struct Nyaa
{
	ll h;
	ll a;
	ll i;
};

auto NyaaSort = [](const Nyaa& l, const Nyaa& r)
{	// 降順は演算子>, 昇順は演算子<, if順の優先でソートされる
	return l.h < r.h;
};

int main(void)
{
	ll N; cin >> N;
	vt<ll> h; InputVT(N, h);
	vt<ll> a; InputVT(N, a);

	vt<Nyaa> f;
	rep(i, 0, N) f.push_back({ h[i], a[i], i });
	sort(all(f), NyaaSort);

	DS_SegmentTree<ll> tree(N);
	each(i, e, f)
	{
		ll test = tree.GetMax(0, e.i);
		tree.Add(e.i, test + e.a);
	}

	cout << tree.GetMax(0, N);
	return 0;
}