#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> food(M, 0);
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int A;
			cin >> A;
			A--;
			food[A]++;
		}
	}
	int count = 0;
	for (int i = 0; i < M; i++) {
		if (food[i] == N) count++;
	}
	cout << count << endl;
	return 0;
}