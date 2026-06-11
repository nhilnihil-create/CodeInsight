#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int K = 0;
	vector<int> A(M + 1);
	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			int rec = 0;
			cin >> rec;
			A[rec]++;
		}
	}
	int count = 0;
	for (int i = 0; i < M + 1; i++) {
		if (A[i] == N) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}