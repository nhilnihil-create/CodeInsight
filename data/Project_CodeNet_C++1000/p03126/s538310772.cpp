#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K, A;
	cin >> N >> M;
	int total = 0;
	vector<int> vec(M);
	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> A;
			vec.at(A - 1)++;
		}
	}
	for (int k = 0; k < M; k++) {
		if (vec.at(k) == N) {
			total++;
		}
	}
	cout << total << endl;
}
