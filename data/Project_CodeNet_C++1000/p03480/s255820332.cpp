#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <climits>
#include <functional>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(int)n;++i)

int a[100010];
int n;
int imos[100010];

bool check(int k)
{
	memset(imos, 0, sizeof imos);

	for (int i = 0; i <= n - k; ++i) {
		if (i > 0) imos[i] += imos[i - 1];
		if ((a[i] + imos[i]) % 2 == 1) {
			imos[i]++;
			imos[i+k]--;
		}
	}
	for (int i = n - k + 1; i < n; ++i) imos[i] += imos[i - 1];

	for (int i = n - k + 1; i <= k - 1; ++i) {
		if ((a[i] + imos[i]) % 2 == 1) {
			return false;
		}
	}

	return true;
}

signed main()
{
	{
		string s; cin >> s;
		n = s.size();

		rep(i, n) a[i] = s[i] - '0';
	}

	int l = 1, r = n + 1;

	while (r - l > 1) {
		int m = (l + r) / 2;

		if (check(m)) {
			l = m;
		} else {
			r = m;
		}
	}

	cout << l << endl;
}
