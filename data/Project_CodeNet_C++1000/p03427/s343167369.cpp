#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	ll	digit;
	ll	count;
	digit = 1;
	count = -1;
	while (n / digit)
	{
		digit *= 10;
		count++;
	}
	ll nine;
	nine = n / (digit / 10) - 1 + 9 * count;
	ll temp;
	temp = n;
	ll original;
	original = 0;
	while (temp)
	{
		original += temp % 10;
		temp /= 10;
	}
	cout << max({original, nine}) << endl;
}
