#include<iostream>
#include<vector>
using namespace std;


int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 3; i <= N; i+=2) {
		int cnt = 0;
		for (int k = 1; k * k < i; k++) {
			if (i % k == 0 && k * k == i) {
				cnt++;
			}
			else if (i % k == 0) {
				cnt += 2;
			}

		}
		if (cnt == 8) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}