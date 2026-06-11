
// D - Good Grid

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N, C;
int D[30][30];
int c[500][500];
int cost[3][30]; // cost[k][d]: (x+y)%3 = k を色dに変えるときの違和感の合計

int calc_cost(int k, int d_to) {
	int result = 0;

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if ((i+j) % 3 == k) {
				int d_from = c[i][j];
				result += D[d_from][d_to];
			}
		}
	}

	//cout << "k=" << k << " d_to=" << d_to << " cost=" << result << endl; // **** debug ****
	return result;
}

int main() {
	cin >> N >> C;

	for (int i=0; i<C; i++) {
		for (int j=0; j<C; j++) {
			cin >> D[i][j];
		}
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cin >> c[i][j];
			c[i][j]--;
		}
	}

	for (int k=0; k<3; k++) {
		for (int d=0; d<C; d++) {
			cost[k][d] = calc_cost(k, d);
		}
	}

	int ans = INF;

	for (int d1=0; d1<C; d1++) {
		for (int d2=0; d2<C; d2++) {
			for (int d3=0; d3<C; d3++) {
				if (d1 == d2 || d2 == d3 || d3 == d1) continue;
				else ans = min(ans, cost[0][d1] + cost[1][d2] + cost[2][d3]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}