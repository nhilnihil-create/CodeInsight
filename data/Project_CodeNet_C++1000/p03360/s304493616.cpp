#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, K;
	vector<int> vec(3);
	for (int i = 0; i < 3; i++) {
		cin >> A;
		vec.at(i) = A;
	}
	sort(vec.begin(), vec.end());
	cin >> K;
	for (int j = 0; j < K; j++) {
		vec.at(2) *= 2;
	}
	int total = vec.at(0) + vec.at(1) + vec.at(2);
	cout << total << endl;
}