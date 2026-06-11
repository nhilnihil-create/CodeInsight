// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, d;
	cin >> n >> m >> d;


	long long pairs = d ? 2 * (n-d) : n;

	double p = 1.0 * pairs / (1ll*n*n);

	cout << fixed << setprecision(10) << (m-1) * p;


	
	return 0;
}
