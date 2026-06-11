#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

// Use g++ compiler for this include to work.
#include <bits/stdc++.h>

using namespace std;

// Constants 
#define INF 1e18
#define EPS 1e-9
#define MOD 1000000007
 
// // for using in pairs
#define F first
#define S second
 
// Macros
#define all(x) begin(x), end(x)
 
// aliases
using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using ld = long double;

// Temporary macro.
#define int long long

// Operator overloads.
/**
 * The type of element in the vector should have overload for << operator with ostream. 
 */
template<typename T>
ostream& operator<<(ostream &stream, vector<T> v)
{
	for (const auto &it : v)
		stream << it << " ";
	return stream;
}

/**
 * Both types in the pair should have overload for << operator with ostream. 
 */
template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, pair<T1, T2> p)
{
	ostream << p.first << " " << p.second;
	return ostream;
}

template<typename T>
void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

// Utility functions.
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int GCD(int a, int b)
{
	if (!b)
		return a;
	return GCD(b, a % b);
}

int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

int modpow(int x, int n, int m = MOD)
{
	if (n == 0) return 1 % m;
	long long u = modpow(x, n / 2, m);
	u = (u * u) % m;
	if (n % 2 == 1)
		u = (u * x) % m;
	return u;	
}

//////////////////// START CODE HERE ///////////////////////////


void solve(int tc)
{
	int n;
	cin >> n;
	ld p[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];

	ld dp[n + 1][n + 1];
	// dp[i][j]: probability of getting j heads using upto i coins
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (int j = 1; j <= n; j++)
		dp[0][j] = 0;

	ld ans = 0;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// If we get tails
			dp[i][j] = dp[i - 1][j]  * (1 - p[i - 1]);
			dp[i][j] += dp[i - 1][j - 1] * p[i - 1];

			// if (j > n / 2)
			// {
			// 	ans += dp[i][j];
			// 	count++;
			// }
		}
	}

	// for (int i = 0; i <= n; i++)
	// {
	// 	for (int j = 0; j <= n; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// ans /= count;
	cout << setprecision(10) << dp[n][n / 2 + 1] << "\n";

}

int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	// cin >> t;		
	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}

	return 0;
}
