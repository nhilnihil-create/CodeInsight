
// D - Cake 123

// 解説pdfの解法 #2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll A[1000], B[1000], C[1000];

int main() {
	ll X, Y, Z, K;
	cin >> X >> Y >> Z >> K;

	for (int i=0; i<X; i++) {
		cin >> A[i];
	}
	sort(A, A+X, greater<ll>());

	for (int i=0; i<Y; i++) {
		cin >> B[i];
	}
	sort(B, B+Y, greater<ll>());

	for (int i=0; i<Z; i++) {
		cin >> C[i];
	}
	sort(C, C+Z, greater<ll>());

	vector<ll> P;
	for (int i=0; i<X; i++) {
		for (int j=0; j<Y; j++) {
			for (int k=0; k<Z; k++) {
				if ((i+1) * (j+1) * (k+1) > K) break;
				else P.push_back(A[i] + B[j] + C[k]);
			}
		}
	}

	sort(P.begin(), P.end(), greater<ll>());

	for (int i=0; i<K; i++) {
		cout << P[i] << endl;
	}

	return 0;
}