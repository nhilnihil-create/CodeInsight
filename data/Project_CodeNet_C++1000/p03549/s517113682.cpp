#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int x = (1900 * m) + (100 * (n - m));
	double p = 1 / pow(2, m);

	int ans = x / p;

	cout << ans << endl;
}

