
// C - Many Medians

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int X[200000];
int sX[200000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> X[i];
		sX[i] = X[i];
	}

	sort(sX, sX+N);
	int L = sX[N/2 - 1];
	int R = sX[N/2];

	for (int i=0; i<N; i++) {
		if (X[i] <= L) cout << R << endl;
		else cout << L << endl;
	}

	return 0;
}