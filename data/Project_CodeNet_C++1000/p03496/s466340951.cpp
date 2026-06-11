#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	long long a[n];

	int mini;
	long long minv;
	int maxi;
	long long maxv;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) {
			mini = i;
			minv = a[i];
			maxi = i;
			maxv = a[i];
		} else {
			if (minv > a[i]) {
				minv = a[i];
				mini = i;
			}
			if (maxv < a[i]) {
				maxv = a[i];
				maxi = i;
			}
		}
	}
	vector<pair<int, int>> ans;
	bool plus = true;
	if (minv < 0)
		plus = false;

	if ((minv * maxv) < 0) {
		if (abs(minv) > abs(maxv)) {
			for (int i = 0; i < n; i++) {
				if (a[i] > 0) {
					a[i] += minv;
					ans.push_back(make_pair(mini+1, i+1));
				}
			}
			plus = false;
		} else {
			for (int i = 0; i < n; i++) {
				if (a[i] < 0) {
					a[i] += maxv;
					ans.push_back(make_pair(maxi+1, i+1));
				}
			}
			plus = true;
		}
	}

	if (plus) {
		for (int i = 0; i < n-1; i++) {
			if (a[i] > a[i+1]) {
				a[i+1] += a[i];
				ans.push_back(make_pair(i+1, i+1+1));
			}
		}
	} else {
		for (int i = n-1; i > 0; i--) {
			if (a[i-1] > a[i]) {
				a[i-1] += a[i];
				ans.push_back(make_pair(i+1, i-1+1));
			}
		}
	}

	cout << ans.size() << endl;
	for (auto e : ans) {
		printf("%d %d\n", e.first, e.second);
	}
	return 0;
}