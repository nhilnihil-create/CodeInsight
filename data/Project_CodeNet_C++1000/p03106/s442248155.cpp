#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define inf 1e10
#define mod 1000000007
#define mii map<int,int>
#define pii pair<int,int>
#define setbits(x) __builtin_popcountll(x)
#define lcm(x,y)  (x*y)/__gcd(x,y)
void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int  fact(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * fact(n - 1);
}
int nCr(int n, int r)
{
	if (r == 0)
		return 1;
	else
		return fact(n) / (fact(n - r) * fact(r));
}
int floorRoot5(int n)
{
	// Base cases
	if (n == 0 || n == 1)
		return n;

	// Initialize result
	int res = 0;

	// Keep incrementing res while res^5 is
	// smaller than or equal to n
	while (res * res * res * res * res <= n)
		res++;

	// Return floor of 5'th root
	return res - 1;
}

int32_t main()
{
	//c_p_c();
	int a, b, k;
	cin >> a >> b >> k;
	int i = 1;
	vi v;
	for (i = min(a, b); i >= 1; i--)
	{
		if (a % i == 0 && b % i == 0)
			v.pb(i);
	}
	// for (auto &it : v)
	// 	cout << it << " ";
	cout << v[k - 1];

}

