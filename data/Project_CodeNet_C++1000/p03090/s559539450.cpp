#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, ar, r;
	cin >> n;
	ar = (n-1)*n>>1;
	cout << ar-(n>>1) << "\n";
	r = n - (n&1);
	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			if (j == r-i+1) continue;
			cout << i << " " << j << "\n";
		}
	}
	return 0;
}
