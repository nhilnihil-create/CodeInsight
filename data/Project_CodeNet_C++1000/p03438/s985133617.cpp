#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	vector<int>b(n);
	for (int i = 0; i < n; i++)cin >> b.at(i);
	vector<int>c(n);
	for (int i = 0; i < n; i++)c.at(i) = a.at(i) - b.at(i);
	sort(c.begin(), c.end());
	ll plus = 0;
	ll total = 0;
	ll mc = 0;
	for (int i = 0; i < n; i++) {
		if (c.at(i) > 0)plus += c.at(i);
		else if (c.at(i) < 0)mc += abs(c.at(i)) / 2;
		total += c.at(i);
	}
	if (total>0||mc<plus)cout << "No" << endl;
	else cout << "Yes" << endl;
}