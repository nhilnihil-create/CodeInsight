#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int sum=0;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	for (int i=1; i<n; i++) {
		sum+=a[i];
	}
	sum+=(a[0]/2);
	cout << sum;
	return 0;
}