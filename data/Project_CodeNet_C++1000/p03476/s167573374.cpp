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

bool IsPrime(int num)
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

int main()
{
	vector<ll> pl(100001);
	rep(i, 100001) {
		if (IsPrime(i)) {
			pl[i] = 1;
		}
	}
	vector<ll> al(100001);
	rep(i, 100001) {
		if (i % 2 == 1) {
			if (pl[(i + 1) / 2] == 1 && pl[i] == 1)
			{
				al[i] = 1;
			}
		}
		if (i - 1 > 0) {
			al[i] += al[i - 1];
		}
	}
	ll n;
	cin >> n;
	vector<ll> ansl;
	rep(i, n) {
		ll l, r;
		cin >> l >> r;
		ansl.push_back(al[r] - al[max(l - 1, (ll)0)]);
	}
	rep(i, n) {
		cout << ansl[i] << endl;
	}
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}
