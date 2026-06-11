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
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> pl(n);
	rep(i, n) {
		ll x, y;
		cin >> x >> y;
		pl[i] = pair<ll, ll>(x, y);
	}
	sort(pl.begin(), pl.end());
	ll tmp = 0;
	ll ans = 0;
	rep(i, n) {
		if (m > tmp + pl[i].second) {
			ans += pl[i].second * pl[i].first;
			tmp += pl[i].second;
		}
		else{
			ans += (m - tmp) * pl[i].first;
			break;
		}
	}
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}

