#include<iostream>
#include<algorithm>
using namespace std;

int a[60];

int main() {
	int N; cin >> N;
	int maxNum = 0, point = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (abs(a[i]) > maxNum) {
			maxNum = abs(a[i]);
			point = i;
		}
	}
	cout << N * 2 - 1 << endl;
	for (int i = 0; i < N; i++) {
		cout << point + 1 << " " << i + 1 << endl;
	}
	if (a[point] >= 0) {
		for (int i = 0; i < N - 1; i++) {
			cout << i + 1 << " " << i + 2 << endl;
		}
	}
	else {
		for (int i = N - 1; i > 0; i--) {
			cout << i + 1 << " " << i << endl;
		}
	}

	return 0;
}