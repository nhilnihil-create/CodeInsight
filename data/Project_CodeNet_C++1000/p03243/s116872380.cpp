#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int num;
	int ans;
	for (int i = 1; i < 10; i++) {
		num = i*100 + i*10 + i;
		if (n <= num) {
			ans = num;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
