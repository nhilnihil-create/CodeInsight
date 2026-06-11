/*
Dont BLUNDER
*/

// #pragma GCC optimize("O3")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimization ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include<climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


 */
//#define d long double
#define int long long
#define pii pair<int,int>
#define pb push_back
#define endl '\n'
#define pi acos(-1)

#define init(x,a) memset(x,a,sizeof(x))
#define all(c) c.begin(),c.end()
int const mod1 = 998244353;
int const mod = 1000000007;
#define bitcount(x)       __builtin_popcountll(x)
#define l first
#define r second
const int inf = LLONG_MAX;
int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
string tostring ( int number ) {stringstream ss; ss << number; return ss.str();}
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define haha ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// * Using PBDS *
/*typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
               os; */

struct cmp
{
	bool operator() (pii a, pii b) {
		return (a.l < b.l);
	}
};

int modexp(int x, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n & 1) {
		return (modexp((x * x) % mod, n / 2) % mod * x % mod) % mod;
	}
	else {
		return (modexp((x * x) % mod, n / 2) % mod);
	}
}

int modinv(int n)
{
	return modexp(n, mod - 2);
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int dp[100001][2];
int n, k;
int arr[101];

int go(int sum, int turn) {
	if (sum < 0) {
		return turn;
	}
	if (sum < arr[0]) {
		return turn ^ 1;

	}
	if (dp[sum][turn] != -1)
		return dp[sum][turn];


	for (int i = 0; i < n; i++) {
		int op2 = go(sum - arr[i] , turn ^ 1);
		//cout << op2 << " " << sum << " " << arr[i] << " " << turn << endl;
		if (op2 == turn )
		{
			return dp[sum][turn] = turn;
		}

	}
	return dp[sum][turn] = turn ^ 1;



}





signed main()
{
	haha
#ifndef ONLINE_JUDGE

	freopen("inp.txt", "r", stdin);

	freopen("out1.txt", "w", stdout);
#endif
	init(dp, -1);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x = go(k, 0);

	if (x == 0)
		cout << "First";
	else {
		cout << "Second";
	}







}
