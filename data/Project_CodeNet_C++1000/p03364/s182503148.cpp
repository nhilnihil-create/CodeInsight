#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> S(N);
	for (int i = 0; i < N; i++) cin >> S[i];
	int ans = 0;
	for (int A = 0; A < N; A++) {
		int sum = N;
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				if (S[(i+A)%N][j] != S[(j+A)%N][i]) {
					sum = 0;
					break;
				}
			}
		}
		ans += sum;
	}
	cout << ans << endl;
}