#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	string a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (a.at(i) == b.at(i) && b.at(i) == c.at(i))continue;
		else if (a.at(i) != b.at(i) && b.at(i) != c.at(i)&&a.at(i)!=c.at(i))ans += 2;
		else ans += 1;
	}
	cout << ans << endl;
}