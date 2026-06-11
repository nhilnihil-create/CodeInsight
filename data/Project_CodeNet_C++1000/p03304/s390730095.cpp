
// C - Ordinary Beauty

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll n, m, d;
	cin >> n >> m >> d;

	double beauty;
	if (d == 0) beauty = n;
	else beauty = max(0LL, n-d) * 2;

	//cout << "beauty = " << beauty << endl; // **** debug ****

	double ans = beauty / (n * n);

	for (int i=3; i<=m; i++) {
		ans = ans + beauty / (n * n);
	}

	cout << fixed << setprecision(10);
	cout << ans << endl;

	return 0;
}

//ans(i) = ( ans(i-1) * n^(i-1) * n + beauty * n^(i-2) ) / n^i
//       = ans(i-1) + beauty / n