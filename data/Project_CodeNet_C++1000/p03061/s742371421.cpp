#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	vector<int>sigfront(n);
	sigfront.at(0) = 0;
	for (int i = 1; i < n; i++) {
		if (i == 1)sigfront.at(i) = a.at(0);
		else sigfront.at(i) = __gcd(sigfront.at(i - 1), a.at(i - 1));
	}
	vector<int>sigback(n);
	sigback.at(0) = 0;
	for (int i = 1; i < n; i++) {
		if (i == 1)sigback.at(i) = a.at(n - 1);
		else sigback.at(i) = __gcd(sigback.at(i - 1), a.at(n - i));
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (sigfront.at(i) == 0 || sigback.at(n - 1 - i) == 0)ans = max(ans, max(sigfront.at(i), sigback.at(n - 1 - i)));
		else ans = max(ans, __gcd(sigfront.at(i), sigback.at(n - 1 - i)));
	}
	cout << ans << endl;
}