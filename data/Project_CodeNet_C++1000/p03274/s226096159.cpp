#include "bits/stdc++.h"
using namespace std;

//20
typedef long long ll;
			
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	//ll ans = 0;
	int minn = 1e9 + 7;
	for (int i = k - 1; i < n; ++i) {
		int a = 0;
		if (v[i - k + 1] < 0) {
			a += abs(v[i - k + 1]);
		}
		if (v[i] > 0) {
			a += 2 * v[i];
		}
		minn = min(minn,a);
	}
	for (int i = k - 1; i < n; ++i) {
		int a = 0;
		if (v[i - k + 1] < 0) {
			a += 2 * abs(v[i - k + 1]);
		}
		if (v[i] > 0) {
			a += v[i];
		}
		minn = min(minn,a);
	}
	cout << minn;
}
