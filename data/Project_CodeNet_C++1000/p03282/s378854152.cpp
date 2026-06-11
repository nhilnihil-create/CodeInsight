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
	string s;
	ll k;
	cin >> s >> k;
	ll tmp = 0;
	vector<ll> l;
	rep(i, s.size()) {
		ll num = s[i] - '0';
		l.push_back(num);
	}
	int ans = 0;
	rep(i, s.size()) {
		if (l[i] != 1) {
			ans = l[i];
			break;
		}
		if (i + 1 == k) {
			ans = 1;
			break;
		}
	}
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}

