#include <iostream>
using namespace std;

int main() {
	int n[3];
	int k;
	for (int i = 0; i < 3; i++) {
		cin >> n[i];
	}
	cin >> k;

	int max = 0;
	int num;
	for (int i = 0; i < 3; i++) {
		if (max < n[i]) {
			max = n[i];
			num = i;
		}
	}

	int ans = 0;
	if (num == 0) {
		ans = n[1]+n[2];
	} else if (num == 1) {
		ans = n[0]+n[2];
	} else {
		ans = n[0]+n[1];
	}
	for (int i = 0; i < k; i++) {
		n[num] *= 2;
	}
	ans += n[num];
	cout << ans << endl;
	return 0;
}
  