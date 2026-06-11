#include<iostream>
using namespace std;

int N, A[200000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	if (A[0] != 0) {
		cout << -1 << endl;
		return 0;
	}

	long long ans = 0;
	int now_height = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] < now_height) {
			cout << -1 << endl;
			return 0;
		}
		if (A[i] > now_height) {
			ans += A[i];
			now_height = A[i];
		}
		if (now_height > 0) {
			now_height--;
		}
	}
	cout << ans << endl;

	return 0;
}