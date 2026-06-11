#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	double sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	double mean = sum / N;
	double MIN = 9999;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (MIN > abs(mean - A[i])) {
			ans = i;
			MIN = abs(mean - A[i]);
		}
	}
	cout << ans << endl;
}