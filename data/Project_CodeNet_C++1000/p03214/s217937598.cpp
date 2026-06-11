#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);

	double ave = 0;
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
		ave += A.at(i);
	}

	ave /= N;
	int num = 0;
	double diff = abs(A[0] - ave);
	for (int i = 1; i < N; i++) {
		if (diff > abs(A[i] - ave)) {
			num = i;
			diff = abs(A[i] - ave);
		}
	}
	
	cout << num << endl;

	return 0;
}