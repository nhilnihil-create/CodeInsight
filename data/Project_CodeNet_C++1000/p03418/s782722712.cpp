#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	long long ret = 0;
	for (int i = k + 1; i <= n; ++i) {
		if (k == 0) {
			ret += n;
			continue;
		}
		int j = n / i;
		ret += j * (i - k);
		ret += max(0, n - i * j - k + 1);
	}
	cout << ret << endl;

	return 0;
}