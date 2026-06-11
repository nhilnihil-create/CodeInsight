#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n, count = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i += 2) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				count++;
			}
		}
		if (count == 8) {
			ans++;
		}
		count = 0;
	}
	cout << ans << endl;
	return 0;
}