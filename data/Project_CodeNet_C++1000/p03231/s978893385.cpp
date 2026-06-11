#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion

#pragma region GCD
ll gcd(ll a, ll b)
{
	if (a%b == 0)return b;
	return gcd(b, a%b);
}
#pragma endregion
#pragma region LCM
ll lcm(ll a, ll b)
{
	return (a*b) / gcd(a, b);
}
#pragma endregion

int main()
{
	ll n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	if (s[0] != t[0])
	{
		cout << -1 << endl;
	}
	else
	{
		int nd = n / gcd(n, m);
		int md = m / gcd(n, m);
		string a = "", b = "";
		for (int i = nd; i < n; i += nd)a += s[i];
		for (int i = md; i < m; i += md)b += t[i];
		if (a == b)cout << lcm(n, m) << endl;
		else cout << -1 << endl;
	}
}