#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n; cin >> n;
	vector<ll> x(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	vector<ll> x_sort;
	x_sort = x;
	sort(x_sort.begin(), x_sort.end());
	for (int i = 1; i <= n; i++) {
		if (x[i] <= x_sort[n / 2])	cout << x_sort[n / 2 + 1] << endl;
		else cout << x_sort[n / 2] << endl;
	}
	return 0;
}