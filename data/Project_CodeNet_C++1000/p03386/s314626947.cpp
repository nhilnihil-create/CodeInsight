#include <iostream>

using namespace std;

int main() {
	int A, B, K;
	cin >> A >> B >> K;
	int ans[200];
	// 配列を-1に初期化
	for (int i = 0; i < 200; i++) {
		ans[i] = -1;
	}

	// AからA+Kまでを配列に追加
	for (int i = 0; i < K; i++) {
		ans[i] = A + i;
		if(ans[i] == B) {
			for (int j = 0; j <= i; j++) cout << ans[j] << "\n";
			return 0;
		}
	}

	for (int i = 0; i < K; i++) {
		int tmp = B - K + 1 + i;
		if (tmp <= ans[K - 1]) {
			continue;
		}	
		else {
			ans[i + K] = tmp;	// そうでなければ配列に格納する
		}	
	}

	for (int i = 0; i < 2*K; i++) {
		if(ans[i] == -1) continue;
		cout << ans[i] << "\n";
	}
}