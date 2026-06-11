#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1010101010

using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long ans = 0;
	for (long long i = 1; i * i < n; i++) {
		long long t = (n - i) / i;
		if ((n - i) % i == 0 && n / t == n % t) {
			ans += (n - i) / i;
		}
	}
	cout << ans << endl;

	return 0;
}