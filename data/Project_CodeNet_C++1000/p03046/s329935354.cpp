#include <bits/stdc++.h>
#include <boost/range/adaptors.hpp>
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
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define mod 1000000007                           // 1e9 + 7
#define pi 3.14159265                            // 3.14 ...
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, v) fori(i, auto& e: v)
#define forir(i, ...) if(ll i = Size(v)) for(__VA_ARGS__) if(i--, true)
#define eachr(i, e, v) forir(i, auto& e: boost::adaptors::reverse(v))

/***** lambda *****/
auto Bit = [] // long long bit shift
(auto n) { return (1LL << n); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto Divc = []  // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Size = []  // long long collection size
(auto& c) { return (ll)(c).size(); };
auto Sum = []   // long long accumulate
(auto b, auto e) { return accumulate(b, e, 0LL); };
auto VVT = []   // vector<vector<T>> resize 
(auto& vvt, auto ysize, auto xsize)
{ vvt.resize(ysize); each(i, vy, vvt) vy.resize(xsize); };
auto VVVT = []   // vector<vector<vector<T>>> resize 
(auto& vvvt, auto zsize, auto ysize, auto xsize)
{ vvvt.resize(zsize); each(z, vz, vvvt) VVT(vz, ysize, xsize); };
auto InVVT = []  // input vector<vector<T>> (T != struct)
(auto& vvt) { each(y, vy, vvt) each(x, e, vy) cin >> e; };
auto InVVVT = [] // input vector<vector<vector<T>>> (T != struct)
(auto& vvvt) { each(z, vz, vvvt) InVVT(vz); };

struct Nya
{
	ll k = 0;
	vt<ll> n;
};

auto NyaSort = [](const Nya& l, const Nya& r)
{	// 降順は演算子>, 昇順は演算子<, if順の優先でソートされる
	return l.k < r.k;
};

int main(void)
{
	ll M, K; cin >> M >> K;
	
	if (Bit(M) <= K)
	{
		cout << -1;
		return 0;
	}

	if (M == 1)
	{
		if (K == 0) cout << "0 0 1 1";
		else cout << -1;
		return 0;
	}

	rep(i, 0, Bit(M))
		if (i != K) cout << i << " ";
	cout << K << " ";
	repr(i, Bit(M) - 1, -1)
		if (i != K) cout << i << " ";
	cout << K;

	return 0;

	/** 以下シミュレーション用プログラム ******/
	/** (実装に時間かかるので現実的ではない) **/
	
	vt<ll> v;
	rep(i, 0, Bit(M)) v.push_back(i);
	rep(i, 0, Bit(M)) v.push_back(i);
	sort(all(v));

	ll times = 0;
	vector<ll> testv;
	vector<Nya> nya;
	do {
		testv.clear();
		rep(i, 0, Size(v)-1)
		{
			ll test = 0;
			rep(j, i + 1, Size(v))
			{
				if (v[i] == v[j])
				{
					rep(k, i, j + 1) test ^= v[k];
					testv.push_back(test);
					break;
				}
			}
		}
		if (count(all(testv), testv[0]) == Size(testv)) {
			nya.push_back({ testv[0], vt<ll>() });
			each(i, e, v) nya.back().n.push_back(e);
			testv.push_back(testv[0]);
		}
		if (++times == 1000000) break;
	} while (std::next_permutation(all(v)));

	sort(all(nya), NyaSort);
	each(i, e, nya)
	{
		cout << "k=" << e.k << "|";
		each(j, en, e.n) cout << en << " ";
		cout << endl;
	}
	return 0;
}

