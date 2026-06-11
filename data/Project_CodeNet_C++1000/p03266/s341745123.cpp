#include <iostream>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;

	long long ans = (n / k) * (n / k) * (n / k);
	if (k % 2 == 0) {
		long long t = n / (k / 2) - n / k;
		ans += t * t * t;
	}
	cout << ans << endl;

	return 0;
}