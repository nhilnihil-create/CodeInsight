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
	ll n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>> al(510, vector<ll>(510));
	vector<vector<ll>> sum(510, vector<ll>(510));
	rep(i, m) {
		ll l, r;
		cin >> l >> r;
		al[l][r] += 1;
	}
	repi(i, 1, 510) {
		repi(j, 1, 510) {
			sum[i][j] = al[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	vector<ll> ansl(q);
	rep(i, q) {
		ll ans = 0;
		ll l, r;
		cin >> l >> r;
		ans = sum[r][r] - sum[r][l - 1] - sum[l - 1][r] + sum[l - 1][l - 1];
		ansl[i] = ans;
	}
	rep(i, q) {
		cout << ansl[i] << endl;
	}
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}
