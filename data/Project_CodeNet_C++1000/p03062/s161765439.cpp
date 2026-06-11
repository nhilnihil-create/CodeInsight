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
const int MOD = 1000000007;
const long long llINF = 1LL << 60;
map<int, int> mp;
int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	int minusNum = 0;
	ll ans = 0;
	ll absMin = llINF;
	rep(i, n) {
		cin >> a[i];
		ans += abs(a[i]);
		absMin = min(absMin, abs(a[i]));
		if (a[i] < 0) {
			minusNum++;
		}
	}
	if (minusNum % 2 == 1) {
		ans -= ll(2) * absMin;
	}
	cout << ans << endl;
	return 0;
}
