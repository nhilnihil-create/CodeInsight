#include <bits/stdc++.h>

using namespace std;

int main(void)
{

	int n, k;
	cin >> n >> k;
	vector<int> x(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}

	int res = 1000000000;
	for (int i = 1; i <= n - k+1; i++) {
		res = min(res, min(abs(x[i]) + x[i + k - 1] - x[i], abs(x[i+k-1]) + abs(x[i + k - 1] - x[i])));
	}
	cout << res << endl;

	return 0;
}