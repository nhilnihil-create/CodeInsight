#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int sub = b - a;
	int low = 0;
	for (int i = 0; i < sub; i++) {
		low += i;
	}
	int ans = low - a;
	cout << ans << endl;
	return 0;
}