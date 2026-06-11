#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N;
	scanf("%d", &N);

	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	vector<int> result(N);
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			if (B[j] == j + 1) {
				B.erase(B.begin() + j);
				result[i] = j + 1;
				goto find;
			}
		}
		printf("-1");
		return 0;
	find:
		continue;
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}