#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

/***** type *****/
using namespace std;
using ll = long long;
using ld = long double;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
using ml = boost::multiprecision::cpp_int;

/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define val(itr) *(itr)                          // get value
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define pi 3.1415926535897932                    // 3.14 ...
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, c) fori(i, auto e = c.begin(); e != c.end(); ++e)
#define forir(i, v, ...) if(ll i=(ll)v.size())for(__VA_ARGS__)if(i--,true)
#define eachr(i, e, c) forir(i, auto e = c.rbegin(); e != c.rend(); ++e)

/***** lambda *****/
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoN = [] // char to number
(auto c) { return (ll)(c - '0'); };
auto DivC = [] // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it)*it += fix; };
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
template <class T> vvt<T> VVT
(ll ys, ll xs, T fill = T())
{	// vector<vector<T>> resize + fill
	vvt<T> v(ys);
	each(i, y, v) { y->resize(xs, fill); } return v;
}
template <class T> vvvt<T> VVVT
(ll zs, ll ys, ll xs, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	vvvt<T> v(zs);
	each(i, z, v) { val(z) = VVT(ys, xs, fill); } return v;
}
template <class T> vt<T> InputVT
(ll size, T fix = T())
{	// input vector<T> (T != struct) + fix
	vt<T> v(size);
	rep(i, 0, size) { cin >> v[i]; v[i] += fix; }
	return v;
}
template <class T> vvt<T> InputVVT
(ll ys, ll xs, T fix = T())
{	// input vector<vector<T>> (T != struct) + fix
	vvt<T> v(ys); each(i, y, v) y->resize(xs);
	rep(y, 0, ys) rep(x, 0, xs) { cin >> v[y][x]; v[y][x] += fix; }
	return v;
}
template <class T> vvvt<T> InputVVVT
(ll zs, ll ys, ll xs, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	vvvt<T> v(zs);
	each(i, z, v) { val(z) = InputVVT<T>(ys, xs, fix); }
	return v;
}

namespace NyaGadget
{
	/*** DFSライブラリ ***/

	struct NyaDFS
	{
		// DFSで必ず使う変数
		vector<vector<long long>> g;
		// その他の変数
		vector<long long> vdata;
		vector<unordered_map<long long, long long>> edata;

		/**
		@brief DFS処理関数
		@param r 頂点vの根
		@param v 現在の頂点
		**/
		void Run(long long r, long long v)
		{
			{
				// 頂点の更新処理
			}
			for (auto e : g[v])
			{	// 後戻りしないようにする
				if (e == r) continue;
				{ // 辺の更新処理
					if (edata[v][e] % 2 == 1) vdata[e] = abs(vdata[v] - 1);
					else vdata[e] = vdata[v];
				}
				Run(v, e);
			}
		}
	};
}

using namespace NyaGadget;
//using mll = ModLL<1000000007>;

struct Sushi
{
	ll t;
	ll d;
};

auto NyaSort = [](const Sushi& l, const Sushi& r)
{	// 降順は演算子>, 昇順は演算子<, if順の優先でソートされる
	return l.d > r.d;
};

bool operator< (const Sushi& l, const Sushi& r)
{	// priority_queueを降順でソートする
	// 昇順にしたいときは不等号を「>」にする
	return l.d > r.d;
};

int main()
{
	ll N, K; cin >> N >> K;
	vt<Sushi> sushi(N); each(i, e, sushi) cin >> e->t >> e->d;
	sort(all(sushi), NyaSort);

	ll dsum = 0;
	ll countType = 0;
	vt<bool> selected(N+1, false);
	priority_queue<Sushi> spq;
	rep(i, 0, K)
	{
		if (selected[sushi[i].t])
		{
			spq.push({ sushi[i].t, sushi[i].d });
			dsum += sushi[i].d;
		}
		else
		{
			dsum += sushi[i].d;
			selected[sushi[i].t] = true;
			countType++;
		}
	}

	ll ans = dsum + countType * countType;	
	rep(i, K, N)
	{
		if (Size(spq) == 0) break;
		if (!selected[sushi[i].t])
		{
			dsum -= spq.top().d;
			dsum += sushi[i].d;
			countType++;
			selected[sushi[i].t] = true;
			ans = max(ans, dsum + countType * countType);
			spq.pop();
		}
	}

	cout << ans;
	return 0;
}