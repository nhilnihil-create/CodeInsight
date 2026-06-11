#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.rbegin(),v.rend());
	cout << sum - v[0] / 2;
}
