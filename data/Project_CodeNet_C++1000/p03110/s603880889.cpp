#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	const int f = 380000;
	double  ans = 0;
	for (int i = 0; i < n; i++) {
		double x; string s; cin >> x >> s;
		if (s == "JPY") {
			ans+=x;
		}
		else {
			ans+=x*f;
		}
	}
	cout << fixed << setprecision(11) << ans << endl;
	return 0;
}