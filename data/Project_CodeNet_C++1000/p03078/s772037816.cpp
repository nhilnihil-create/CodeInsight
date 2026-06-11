
// D - Cake 123

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

	for (int i=0; i<Y; i++) {
		cin >> B[i];
	}

	for (int i=0; i<Z; i++) {
		cin >> C[i];
	}

	vector<ll> P;
	P.reserve(X*Y);
	for (int i=0; i<X; i++) {
		for (int j=0; j<Y; j++) {
			P.push_back(A[i] + B[j]);
		}
	}

	sort(P.begin(), P.end(), greater<ll>());

	vector<ll> Q;
	Q.reserve(K * Z);
	for (int i=0; i<min(K, X*Y); i++) {
		for (int j=0; j<Z; j++) {
			Q.push_back(P[i] + C[j]);
		}
	}

	sort(Q.begin(), Q.end(), greater<ll>());

	for (int i=0; i<K; i++) {
		cout << Q[i] << endl;
	}

	return 0;
}