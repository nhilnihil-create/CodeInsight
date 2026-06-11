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
	ll n;
	cin >> n;
	vector<ll> al(n);
	vector<ll> sum(n + 1);
	rep(i, n) {
		ll a;
		cin >> a;
		al[i] = a;
		sum[i + 1] = sum[i] + a;
	}
	map<ll, ll> mp;
	for (auto item : sum) {
		mp[item]++;
	}
	ll ans = 0;
	for(auto item : mp) {
		ans += (item.second * (item.second - 1)) / 2;
	}
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}
