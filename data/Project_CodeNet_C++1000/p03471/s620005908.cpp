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
	ll n, y;
	cin >> n >> y;
	rep(i, n + 1) {
		rep(j, n + 1) {
			if (n < (i + j)) break;
			ll k = n - (i + j);
			if (y == k * 10000 + j * 5000 + i * 1000) {
				cout << k << endl;
				cout << j << endl;
				cout << i << endl;
				system("pause");
				return 0;
			}
		}
	}
	cout << "-1 -1 -1" << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}

