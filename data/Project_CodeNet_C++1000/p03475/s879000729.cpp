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
using p = pair<int, int>;
int main()
{
	int n;
	cin >> n;
	vector<int> c(n - 1), s(n - 1), f(n - 1), ans(n);
	int tmp = 0;
	rep(i, n - 1) {
		cin >> c[i] >> s[i] >> f[i];
	}
	rep(i, n - 1) {
		ans[i] = s[i] + c[i];
		for (int j = i + 1; j < n - 1; ++j) {
			if (ans[i] < s[j])	ans[i] = s[j] + c[j];
			else {
				ans[i] = s[j] + f[j] * ceil(double(ans[i] - s[j]) / f[j]) + c[j];
			}
		}
	}
	ans[n - 1] = 0;

	rep(i, n) {
		cout << ans[i] << endl;
	}
	return 0;
}