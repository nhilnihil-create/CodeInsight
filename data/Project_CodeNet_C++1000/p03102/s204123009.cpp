#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, M, C;
	cin >> N >> M >> C;

	vector<int> B(M);
	for (int i = 0; i < M; i++) cin >> B[i];

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < M; j++) {
			int A;
			cin >> A;
			sum += A * B[j];
		}
		sum += C;
		if (sum > 0) cnt++;
	}

	cout << cnt << endl;
}