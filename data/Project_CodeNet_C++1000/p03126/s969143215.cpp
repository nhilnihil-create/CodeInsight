#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, M, ans = 0;
	cin >> N >> M;

	vector<int> V(M, 0);

	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;

		for (int j = 0; j < K; j++) {
			int A;
			cin >> A;

			A--;

			++V[A];
		}
	}

	for (int i = 0; i < M; i++) if (V[i] == N) ans++;
	
	cout << ans << endl;
}