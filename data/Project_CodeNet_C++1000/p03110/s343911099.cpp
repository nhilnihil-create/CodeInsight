#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	double ans = 0.00;
	while (n--) {
		double x;
		string u;
		cin >> x >> u;
		if (u == "JPY") {
			ans += x;
		}
		else {
			ans += (x * 380000.0);
		}
	}
	cout << setprecision(9) << ans << "\n";
}

