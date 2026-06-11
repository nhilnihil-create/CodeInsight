#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

int gcd(int a, int b)
{
	if (a%b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a%b));
	}
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ll n, x;
	cin >> n >> x;
	vector<ll> subl;
	rep(i, n) {
		ll xx;
		cin >> xx;
		subl.push_back(abs(x - xx));
	}
	ll g = subl[0];
	rep(i, n) {
		g = gcd(subl[i], g);
	}
	cout << g << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}

