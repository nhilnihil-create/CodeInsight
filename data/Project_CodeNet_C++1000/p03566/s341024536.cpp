
// D - AtCoder Express

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int t[100];
float v[100];
float L[40001];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> t[i];
		t[i] *= 2;
	}

	for (int i=0; i<N; i++) {
		cin >> v[i];
		v[i] *= 2;
	}

	for (int i=0; i<40001; i++) {
		L[i] = INF;
	}

	int tot = 0;
	for (int i=0; i<N; i++) {
		int k = tot;
		tot += t[i];
		while (k <= tot) {
			L[k] = min(L[k], v[i]);
			k++;
		}
	}

	L[0] = 0;
	L[tot] = 0;

	for (int k=1; k<=tot; k++) {
		L[k] = min(L[k], L[k-1] + 1);
	}

	for (int k=tot-1; k>=0; k--) {
		L[k] = min(L[k], L[k+1] + 1);
	}

	float ans = 0;
	for (int k=0; k<=tot - 1; k++) {
		if (L[k+1] == L[k] + 1) {
			ans += L[k] + 0.5;
		} else if (L[k+1] == L[k] - 1) {
			ans += L[k] - 0.5;
		} else {
			ans += L[k];
		}
	}

	ans /= 4;
	cout << fixed << setprecision(10);
	cout << ans << endl;

	// **** debug ****
	/*
	for (int k=0; k<=tot; k++) {
		cout << k << " " << L[k] << endl;
	}
	*/

	return 0;
}