#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N, x, a[110] = {}, max=0;

	cin >> N >> x;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);

	for (int i = 0; i < N; i++) {
		x -= a[i];
		if (x < 0) {
			max = i;
			break;
		}
		else if (x == 0) {
			max = i + 1;
		}
		else {
			max = i;
		}
	}
	cout << max << endl;
	return 0;
}