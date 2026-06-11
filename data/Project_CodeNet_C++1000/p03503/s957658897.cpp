#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsOneBit(long long bits, int i) {
	return (bits & (1ll << i)) > 0;
}

int main() {
	int N;
	cin >> N;
	vector<vector<int>> F(N, vector<int>(10)), P(N, vector<int>(11));
	for (int i = 0; i < N; i++) for (int j = 0; j < 10; j++) cin >> F[i][j];
	for (int i = 0; i < N; i++) for (int j = 0; j < 11; j++) cin >> P[i][j];

	int MAX = -1000000001;
	for (int bits = 1; bits < 1024; bits++) {
		int cost = 0;
		for (int shop = 0; shop < N; shop++) {
			int doubled = 0;
			for (int i = 0; i < 10; i++) doubled += IsOneBit(bits,i) * F[shop][i];
			cost += P[shop][doubled];
		}
		MAX = max(MAX, cost);
	}
	cout << MAX << endl;
}
