#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dig (int x) {
	int sum = 0;
	while (x) {
		sum += x%10;
		x /= 10;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, ans = 1e9;
	cin >> n;
	for (int i=1; i<n; i++) {
		ans = min(ans, dig(i)+dig(n-i));
	}
	cout << ans;
	return 0;
}
