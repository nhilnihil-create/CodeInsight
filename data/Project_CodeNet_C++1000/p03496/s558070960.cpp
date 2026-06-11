
// D - Non-decreasing

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int a[50];

int main() {
	int N;
	cin >> N;

	int max_i = 0;
	for (int i=0; i<N; i++) {
		cin >> a[i];
		if (abs(a[i]) > abs(a[max_i])) max_i = i;
	}

	cout << 2 * N - 1 << endl;

	for (int i=0; i<N; i++) {
		a[i] += a[max_i];
		cout << max_i+1 << " " << i+1 << endl;
	}


	if (a[max_i] >= 0) {
		for (int i=0; i<N-1; i++) {
			a[i+1] += a[i];
			cout << i+1 << " " << i+2 << endl;
		}
	} else {
		for (int i=N-1; i>0; i--) {
			a[i-1] += a[i];
			cout << i+1 << " " << i << endl;
		}
	}

	return 0;
}