#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	double N, T, A;
	cin >> N >> T >> A;
	vector<double> H(N);
	vector<double> t(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	for (int i = 0; i < N; i++) {
		t[i] = T - 0.006 * H[i];
	}
	double ans = 100000;
	int rec = 0;
	for (int i = 0; i < N; i++) {
		if (ans > fabs(t[i] - A)) {
			ans = fabs(t[i] - A);
			rec = i + 1;
		}
	}
	cout << rec << endl;
	return 0;
}