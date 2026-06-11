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
#define coutld cout << fixed << setprecision(10) // cout double
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
	/***** グリッド上でのBFS処理ライブラリ *****/

	struct GT_NyaaGridBFS
	{	// 結果を格納する変数
		std::vector<std::vector<long long>> res4;
		long long res6;
		std::vector<std::vector<long long>> res8;

		/**
		@brief 4方向BFS実行関数
		@param start 探索開始座標
		@param grid 入力グリッド
		@param wall 移動不可な値
		@note
		探索開始頂点startから4方向BFSで処理する。
		到達不能な座標は-1を返す。
		**/
		template <class T> decltype(res4)& Run4(std::pair<long long, long long> start, const std::vector<std::vector<T>>& grid, T wall)
		{	// 初期化
			const std::pair<long long, long long> move[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
			const long long inf = -1LL;
			std::queue<std::pair<long long, long long>> q;
			q.push(start);
			// 初期化処理の追加
			res4.resize(grid.size()); for (auto&& e : res4) e.resize(grid[0].size(), inf);
			res4[start.first][start.second] = 0;
			while (!q.empty())
			{
				auto from = q.front(); q.pop();
				for (auto& m : move)
				{
					long long y = from.first + m.first;
					long long x = from.second + m.second;
					if (y < 0 || (long long)grid.size() <= y || x < 0 || (long long)grid[y].size() <= x) continue;
					// 移動不可座標の処理
					if (grid[y][x] == wall) continue;
					// 移動可能座標の処理
					if (res4[y][x] != inf) continue;
					res4[y][x] = res4[from.first][from.second] + 1;
					q.push({ y, x });
				}
			}
			return res4;
		}

		/**
		@brief 6方向BFS実行関数
		@param start 探索開始座標
		@param grid 入力グリッド
		@param wall 移動不可な値
		@note
		探索開始頂点startから6方向BFSで処理する。
		**/
		template <class T> decltype(res6)& Run6(std::pair<long long, long long> start, const std::vector<std::vector<T>>& grid, T wall)
		{	// 初期化
			std::pair<long long, long long> move1[6] = { {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, 1} };
			std::pair<long long, long long> move2[6] = { {-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 0} };
			std::vector<std::vector<bool>> check(grid.size(), std::vector<bool>(grid[0].size(), false));
			check[start.first][start.second] = true;
			std::queue<std::pair<long long, long long>> q;
			q.push(start);
			// 初期化処理の追加
			res6 = 0;
			while (!q.empty())
			{
				auto from = q.front(); q.pop();
				if (from.first % 2 != 0)
				{
					for (auto& m : move1)
					{
						long long y = from.first + m.first;
						long long x = from.second + m.second;
						if (y < 0 || (long long)grid.size() <= y || x < 0 || (long long)grid[y].size() <= x) continue;
						// 移動不可座標の処理
						if (grid[y][x] == wall) continue;
						// 移動可能座標の処理
						if (check[y][x]) continue;
						else check[y][x] = true;
						q.push({ y, x });
					}
				}
				else
				{
					for (auto& m : move2)
					{
						long long y = from.first + m.first;
						long long x = from.second + m.second;
						if (y < 0 || (long long)grid.size() <= y || x < 0 || (long long)grid[y].size() <= x) continue;
						// 移動不可座標の処理
						if (grid[y][x] == wall) continue;
						// 移動可能座標の処理
						if (check[y][x]) continue;
						else check[y][x] = true;
						q.push({ y, x });
					}
				}
			}
			return res6;
		}

		/**
		@brief 8方向BFS実行関数
		@param start 探索開始座標
		@param grid 入力グリッド
		@param wall 移動不可な値
		@note
		探索開始頂点startから8方向BFSで処理する。
		**/
		template <class T> decltype(res8)& Run8(std::pair<long long, long long> start, const std::vector<std::vector<T>>& grid, T wall)
		{	// 初期化
			std::pair<long long, long long> move[8] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
			std::vector<std::vector<bool>> check(grid.size(), std::vector<bool>(grid[0].size(), false));
			check[start.first][start.second] = true;
			std::queue<std::pair<long long, long long>> q;
			q.push(start);
			// 初期化処理の追加
			res8.resize(grid.size()); for (auto& e : res8) e.resize(grid[0].size());
			while (!q.empty())
			{
				auto from = q.front(); q.pop();
				for (auto& m : move)
				{
					long long y = from.first + m.first;
					long long x = from.second + m.second;
					if (y < 0 || (long long)grid.size() <= y || x < 0 || (long long)grid[y].size() <= x) continue;
					// 移動不可座標の処理
					if (grid[y][x] == wall) continue;
					// 移動可能座標の処理
					if (check[y][x]) continue;
					else check[y][x] = true;
					q.push({ y, x });
				}
			}
			return res8;
		}
	};
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = NT_ModLL< 1000000007 >;
//using mll = ModLL< 998244353 >;

int main(void)
{
	ll H, W; cin >> H >> W;
	vvt<char> grid; InputVVT(H, W, grid);

	GT_NyaaGridBFS bfs;
	auto res = bfs.Run4({ 0, 0 }, grid, '#');
	if (res[H - 1][W - 1] == -1) output(-1);

	ll ans = H * W - res[H-1][W-1];
	rep(y, 0, H) rep(x, 0, W) if (grid[y][x] == '#') --ans;
	cout << ans - 1;
	return 0;
}
