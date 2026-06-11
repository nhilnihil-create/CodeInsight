#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int num[3];
	num[0] = a + b;
	num[1] = a - b;
	num[2] = a * b;
	int ans = num[0];
	for (int i = 1; i < 3; i++) {
		if (ans < num[i]) {
			ans = num [i];
		}
	}
	cout << ans << endl;
	return 0;
}