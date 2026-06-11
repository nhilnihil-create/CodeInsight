#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

int main() {
	int N;
	cin >> N;
	ll sum = 0;
	ll minB = INF;
	for (int i = 0; i < N; i++) {
		ll A, B;
		cin >> A >> B;
		sum += A;
		if (A > B) minB = min(minB, B);
	}
	if (minB == INF) cout << 0 << endl;
	else cout << sum - minB << endl;
}
