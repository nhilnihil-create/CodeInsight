#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if (c <= b) {
		cout << b+c;
		return 0;
	}
	int ans = b+b;
	ans += min(c-b, a) + bool(c-b>a);
	cout << ans;
	return 0;
}