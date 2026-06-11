
// D - XXOR

// 一致しない桁を全探索する解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

// 常に50桁で考える（実際は40ビットで十分）
ll A[100000];
ll B[51]; // S[i][j]: Kの左からi桁目がjのときのfの各Aのi桁目が1の数
ll S[51][2]; // S[i][j]: Kの左からi桁目がjのときのfの各Aのi桁目が表す数の和
ll k[51]; // Kのi桁目のビット

int main() {
	ll N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		ll A;
		cin >> A;
		for (int i=50; i>=1; i--) {
			B[i] += A % 2;
			A /= 2;
		}
	}

	/*
	// **** debug ****
	for (int i=0; i<=50; i++) {
		cout << "B[" << i << "] = " << B[i] << endl;
	}
	*/

	for (int i=1; i<=50; i++) {
		S[i][0] = B[i] * pow(2, 50-i);
		S[i][1] = (N - B[i]) * pow(2, 50-i);
	}

	/*
	// **** debug ****
	for (int i=0; i<=50; i++) {
		cout << "S[" << i << "][0] = " << S[i][0] << endl;
		cout << "S[" << i << "][1] = " << S[i][1] << endl;
	}
	*/

	for (int i=50; i>=1; i--) {
		k[i] = K % 2;
		K /= 2;
	}

	ll ans = 0;
	// X = K（すべて一致）の場合
	for (int i=1; i<=50; i++) {
		ans += S[i][k[i]];
	}

	//cout << "X=K: " << ans << endl; // **** debug ****

	// X と K が 左からi桁目でX[i] < K[i] の場合
	bool ignore = true;
	for (int i=1; i<=50; i++) {
		if (k[i]) ignore = false;
		if (ignore) continue; // X > K は対象外
		if (k[i] == 0) continue;

		ll candidate = 0;

		// iより左
		for (int j=1; j<i; j++) {
			candidate += S[j][k[j]]; // 一致
		}

		// i
		candidate += S[i][0]; // X[i] < K[i]

		// iより右
		for (int j=i+1; j<=50; j++) {
			candidate += max(S[j][0], S[j][1]); // どちらでも
		}

		//cout << "i=" << i << " " << candidate << endl; // **** debug ****

		ans = max(ans, candidate);
	}

	cout << ans << endl;

	return 0;
}