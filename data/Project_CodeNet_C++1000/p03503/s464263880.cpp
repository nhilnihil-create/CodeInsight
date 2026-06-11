
// C - Shopping Street

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int F[100];
int P[100][11]; // P[i][j]: 店iと両方が営業している時間帯の個数がjの時の利益

int count_common_bit(int a, int b, int N) {
	int c = a & b;
	int result = 0;
	for (int i=0; i<N; i++) {
		if (c & (1<<i)) result++;
	}

	return result;
}

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		for (int j=0; j<10; j++) {
			int f;
			cin >> f;
			F[i] |= (f<<j);
		}
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<=10; j++) {
			cin >> P[i][j];
		}
	}

	int ans = -INF;
	for (int bit=1; bit<(1<<10); bit++) {
		int tot_P = 0;
		for (int i=0; i<N; i++) {
			int c = count_common_bit(bit, F[i], 10);
			//cout << bitset<10>(bit) << " "; // **** debug ****
			//cout << bitset<10>(F[i]) << " "; // **** debug ****
			//cout << c << " "; // **** debug ****
			//cout << P[i][c] << endl; // **** debug ****
			tot_P += P[i][c];
		}
		ans = max(ans, tot_P);
	}

	cout << ans << endl;

	return 0;
}