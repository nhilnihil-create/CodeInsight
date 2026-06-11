#include <iostream>
#include <vector>

using namespace std;

int main() {
	int M, K;
	cin >> M >> K;
	int max = 1;
	for (int i = 0; i < M; i++) {
		max *= 2;
	}

	//max >= Kの時、M桁目の数がxorにより1になることはないので構成不可
	if (max <= K) {
		cout << -1 << endl;
		return 0;
	}

	//M == 0
	if (M == 0) {
		cout << "0 0" << endl;
		return 0;
	}
	//M == 1
	if (M == 1) {
		if (K == 0) cout << "0 0 1 1" << endl;
		else cout << "-1" << endl;
		return 0;
	}

	//M >= 2であれば解を構成できる
	vector<int> ans(2 * max);
	for (int i = 0; i < max; i++) {
		if (i == K) continue;
		if (i < K)	ans[i] = i;
		else ans[i - 1] = i;
	}
	ans[max-1] = K;
	for (int i = 0; i < max; i++) {
		if (i == K) continue;
		if (i < K)	ans[2 * max - 2 - i] = i;
		else ans[2 * max - 1 - i] = i;
	}

	ans[2 * max -1] = K;

	for (int i : ans) {
		cout << i << " ";
	}

	cout << endl;

	return 0;
}