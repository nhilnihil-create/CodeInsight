#include <iostream>
using namespace std;

int main() {
	int r, d, x_2000;
	cin >> r >> d >> x_2000;

	int num = x_2000;
	int ans;
	for (int i = 0; i < 10; i++) {
		ans = r * num - d;
		cout << ans << endl;
		num = ans;
	}
	return 0;
}