#include <bits/stdc++.h>
using namespace std;

long long n, ans = 0;

int main() {
	cin >> n;
	for (int i = 1; (long long) i * (i + 2) <= n; i++)
		if (!(n % i))
			ans += n / i - 1;
	cout << ans << endl;
}
