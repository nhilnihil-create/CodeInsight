#include <iostream>
using namespace std;

int main() {
	int n[3];
	for (int i = 0; i < 3; i++) {
		cin >> n[i];
	}

	int cnt[3] = {};
	for (int i = 0; i < 3-1; i++) {
		for (int j = i+1; j < 3; j++) {
			if (n[i] != n[j]) {
				cnt[i]++;
				cnt[j]++;
			}
		}
	}

	int ans;
	for (int i = 0; i < 3; i++) {
		if (cnt[i] == 2) {
			ans = n[i];
		}
	}
	cout << ans << endl;
	return 0;
}