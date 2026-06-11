#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
	int n;
	cin >> n;
	vec(int) a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int sum = accumulate(a.begin(), a.end(), 0);
	int ans = -1;
	int diff = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (abs(n*a[i]-sum) < diff) {
			ans = i;
			diff = abs(n*a[i]-sum);
		}
	}
	cout << ans << endl;
}