#include "bits/stdc++.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long double>A(N);
	long double ave = 0;
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
		ave += A.at(i);
	}
	ave /= N;
	int ans = 0;
	long double s = 99999;
	for (int i = 0; i < N; i++) {
		if (abs(A.at(i) - ave) < s) {
			ans = i;
			s = abs(A.at(i) - ave);
		}
	}
	cout << ans << endl;
}