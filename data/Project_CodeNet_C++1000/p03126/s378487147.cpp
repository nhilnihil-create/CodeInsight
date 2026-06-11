#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>


using namespace std;



int main() {

	int N, M, K, * count, ans = 0, f;

	cin >> N >> M;

	count = new int[M];

	for (int i = 0; i < M; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> f;
			count[f - 1]++;
		}
	}

	for (int i = 0; i < M; i++) {
		if (count[i] == N) {
			ans++;
		}
	}

	cout << ans;

	return 0;

}