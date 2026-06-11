#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	int A = 0;
	int B = 0;	
	vector<int>data(N);
	for (int i = 0; i < N; ++i) {
		cin >> data[i];
	}
	sort(data.rbegin(),data.rend());
	for (int i = 0;i<N;++i) {
		if (0 == i%2) {
			A += data[i];
		}
		else {
			B += data[i];
		}
	}
	cout << A - B << endl;
	return 0;
}
