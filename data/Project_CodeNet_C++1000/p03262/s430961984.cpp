#include "bits/stdc++.h"
using namespace std;

//33
typedef long long ll;

double power(double a , ll b) {
	double ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans  * a;
		}
		a = a * a;
		b  /= 2;
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	v[n] = k;
	sort(v.begin(),v.end());
	vector<int> ans(n);
	for (int i = 1; i <= n; ++i) {
		ans[i - 1] = v[i] - v[i - 1];
	}
	int g = 0;
	for (int i = 0; i < n; ++i) {
		g = __gcd(ans[i],g);
	}
	cout << g;
}
