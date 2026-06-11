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
	vector<int> al(n);
	int sum = 0;
	rep(i, n) {
		int a;
		cin >> a;
		al[i] = a;
		int pre = 0;
		if (i - 1 >= 0) {
			pre = al[i - 1];
		}
		sum += abs(a - pre);
	}
	sum += abs(al[n - 1]);
	rep(i, n) {
		int tmp = sum;
		int pre = 0;
		int next = 0;
		if (i - 1 >= 0) {
			pre = al[i - 1];
		}
		if (i + 1 < n) {
			next = al[i + 1];
		}
		tmp -= abs(pre - al[i]);
		tmp -= abs(al[i] - next);
		tmp += abs(pre - next);
		cout << tmp << endl;
	}
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}

