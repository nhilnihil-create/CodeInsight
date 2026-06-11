#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 1 << endl;
	}else if (n < 2 || m < 2) {
		cout << max({ m - 2, n - 2, 0 }) << endl;
	}
	else if (n == 2 || m == 2) {
		cout << 0 << endl;
	}
	else {
		long long ans = (long long)n * m;
		cout << ans - 2 * (n - 2) - 2 * m << endl;
	}

	return 0;
}