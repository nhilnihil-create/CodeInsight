#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int H, W, N, sr, sc;
	string S, T;
	cin >> H >> W >> N >> sr >> sc >> S >> T;
	int L = 1, R = W, U = 1, D = H;
	for (int i = N - 1; i >= 0; i--) {
		if (i < N - 1) {
			switch (T[i]) {
			case 'U':
				D = min(D + 1, H);
				break;
			case 'D':
				U = max(U - 1, 1);
				break;
			case 'L':
				R = min(R + 1, W);
				break;
			case 'R':
				L = max(L - 1, 1);
				break;
			}
			if (L > R || U > D) {
				cout << "NO" << endl;
				return 0;
			}
		}
		switch (S[i]) {
		case 'U':
			U++;
			break;
		case 'D':
			D--;
			break;
		case 'L':
			L++;
			break;
		case 'R':
			R--;
			break;
		}
		if (R < 1 || L > W || D < 1 || U > H) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << (L <= sc && sc <= R && U <= sr && sr <= D ? "YES" : "NO") << endl;
}