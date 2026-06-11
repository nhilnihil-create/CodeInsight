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

int main()
{
	int n;
	cin >> n;
	vector<ll> l(n);
	rep(i, n) {
		cin >> l[i];
	}
	vector<ll> dp(n + 10, INF);
	dp[0] = 0;
	rep(i, n) {
		ll h1 = l[i];
		if (i + 1 < l.size()) chmin(dp[i + 1], dp[i] + abs(h1 - l[i + 1]));
		if (i + 2 < l.size()) chmin(dp[i + 2], dp[i] + abs(h1 - l[i + 2]));
	}
	cout << dp[n - 1] << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}