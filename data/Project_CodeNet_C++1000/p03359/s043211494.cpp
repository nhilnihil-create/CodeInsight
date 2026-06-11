#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int ans = a - 1;
	if (a <= b) {
		ans++;
	}
	cout << ans << endl;
	return 0;
}