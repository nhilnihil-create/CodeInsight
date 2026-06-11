#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, M, C;
	cin >> N >> M >> C;
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int val = C;
		for (int j = 0; j < M; ++j) {
			int x;
			cin >> x;
			val += x * B[j];
		}
		ans += (val > 0);
	}
	cout << ans << endl;
	return 0;
}