
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
ll B[41]; // S[i][j]: K+1の2^iの桁がjのときのfの各Aの2^iの桁が1の数
ll S[41][2]; // S[i][j]: K+1の2^iの桁がjのときのfの各Aの2^iの桁が表す数の和
ll k[41]; // K+1の2^iの桁のビット

int main() {
	ll N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		ll A;
		cin >> A;
		for (int i=0; i<=40; i++) {
			B[i] += A % 2;
			A /= 2;
		}
	}

	/*
	// **** debug ****
	for (int i=0; i<=40; i++) {
		cout << "B[" << i << "] = " << B[i] << endl;
	}
	*/

	for (int i=0; i<=40; i++) {
		S[i][0] = B[i] * pow(2, i);
		S[i][1] = (N - B[i]) * pow(2, i);
	}

	/*
	// **** debug ****
	for (int i=0; i<=40; i++) {
		cout << "S[" << i << "][0] = " << S[i][0] << endl;
		cout << "S[" << i << "][1] = " << S[i][1] << endl;
	}
	*/

	K++;
	int max_i = 0;
	for (int i=0; i<=40; i++) {
		k[i] = K % 2;
		K /= 2;
		if (k[i]) max_i = max(max_i, i);
	}

	ll ans = 0;

	// X と K+1 が 2^i の桁で x < k
	for (int i=0; i<=40; i++) {
		if (k[i] == 0) continue;

		ll candidate = 0;

		// iより右
		for (int j=0; j<i; j++) {
			candidate += max(S[j][0], S[j][1]); // どちらでも
		}

		// i
		candidate += S[i][0];// x < k

		// iより左
		for (int j=i+1; j<=40; j++) {
			candidate += S[j][k[j]]; // 一致
		}

		//cout << "i=" << i << " " << candidate << endl; // **** debug ****

		ans = max(ans, candidate);
	}

	cout << ans << endl;

	return 0;
}