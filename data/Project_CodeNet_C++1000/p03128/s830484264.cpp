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
#define nyan 10                                  // nyan size
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, v) fori(i, auto& e: v)
#define forir(i, ...) if(ll i = Size(v)) for(__VA_ARGS__) if(i--, true)
#define eachr(i, e, v) forir(i, auto& e: boost::adaptors::reverse(v))

/***** lambda *****/
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it)* it += fix; };
auto Bit = [] // long long bit shift
(auto n) { return (1LL << n); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoN = [] // char to number
(auto c) { return (ll)(c - '0'); };
auto DivC = [] // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto NyaN = [] // long long nyan size
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
	each(i, y, v) { y.resize(xs, fill); } return v;
}
template <class T> vvvt<T> VVVT
(ll zs, ll ys, ll xs, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	vvvt<T> v(zs);
	each(i, z, v) { z = VVT(ys, xs, fill); } return v;
}
template <class T> vt<T> InputVT
(ll size, T fix = T())
{   // input vector<T> (T != struct) + fix
	vt<T> v(size);
	each(i, e, v) { cin >> e; e += fix; } return v;
}
template <class T> vvt<T> InputVVT
(ll ys, ll xs, T fix = T())
{   // input vector<vector<T>> (T != struct) + fix
	vvt<T> v(ys); each(i, y, v) y.resize(xs);
	each(i, y, v) each(j, x, y) { cin >> x; x += fix; } return v;
}
template <class T> vvvt<T> InputVVVT
(ll zs, ll ys, ll xs, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	vvvt<T> v(zs);
	each(i, z, v) { z = InputVVT<T>(ys, xs, fix); } return v;
}

struct A
{
	string s;
	ll ssize;
};

string MaxString(string s1, string s2)
{
	if (Size(s1) == Size(s2))
	{
		if (s1 < s2) return s2;
		else return s1;
	}
	else if (Size(s1) < Size(s2))
	{
		return s2;
	}
	return s1;
}

int main(void)
{
	ll N, M; cin >> N >> M;
	vt<A> a(M);
	each(i, e, a)
	{
		cin >> e.s;
		if (e.s == "1") e.ssize = 2;
		if (e.s == "2") e.ssize = 5;
		if (e.s == "3") e.ssize = 5;
		if (e.s == "4") e.ssize = 4;
		if (e.s == "5") e.ssize = 5;
		if (e.s == "6") e.ssize = 6;
		if (e.s == "7") e.ssize = 3;
		if (e.s == "8") e.ssize = 7;
		if (e.s == "9") e.ssize = 6;
	}

	vt<string> dp(N + 1);
	rep(i, 0, N + 1)
	{	// dp loop
		if (i == 0) continue;

		rep(j, 0, M)
		{	// a loop
			if (i == a[j].ssize)
				dp[i] = MaxString(dp[i], dp[i - a[j].ssize] + a[j].s);
			else if (0 < i - a[j].ssize && Size(dp[i-a[j].ssize]) != 0)
				dp[i] = MaxString(dp[i], dp[i - a[j].ssize] + a[j].s);
		}
	}

	cout << dp[N];
	return 0;
}
