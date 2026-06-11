#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// AtCoder Petrozavodsk Contest 001-B, 1032, 41:22(UNSOLVED), 解説AC
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	ll asum, bsum;
	asum = bsum = 0;
	ll diffNumPlus = 0;
	ll diffNumMinus = 0;
	rep(i, n) {
		cin >> a[i];
		asum += a[i];
	}
	rep(i, n) {
		cin >> b[i];
		bsum += b[i];
	}
	rep(i, n) {
		if (a[i] == b[i]) continue;
		if (a[i] > b[i]) diffNumPlus += a[i] - b[i];
		else diffNumMinus += (b[i] + 1 - a[i]) / 2;
	}
	ll diff = bsum - asum;
	if (diff < 0) {
		cout << "No" << endl;
		return 0;
	}
	if (diff < max(diffNumPlus, diffNumMinus)) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}