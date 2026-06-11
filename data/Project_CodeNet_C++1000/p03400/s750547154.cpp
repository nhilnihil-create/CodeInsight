#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, D, X;
	cin >> N >> D >> X;
	vector<int> A(N);
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j*A[i] + 1 <= D; j++) {
			count++;
		}
	}
	cout << count + X << endl;
	return 0;
}