#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, M, X;
	cin >> N >> M >> X;
	vector<int> A(M);
	for (int i = 0; i < M; i++) {
		cin >> A[i];
	}
	int goal = 0;
	int start = 0;
	for (int i = 0; i < M; i++) {
		if (X < A[i]) {
			goal++;
		}
		if (A[i] < X) {
			start++;
		}
	}
	cout << min(goal, start) << endl;
	return 0;
}