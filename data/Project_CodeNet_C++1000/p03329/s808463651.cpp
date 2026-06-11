#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 1001001001;
	for (int i = 0; i <= n; i++) {
		int n6 = i;
		int n9 = n - i;
		int sum = 0;
		while (n6 != 0) {
			sum += n6 % 6;
			n6 /= 6;
		}
		while (n9 != 0) {
			sum += n9 % 9;
			n9 /= 9;
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}