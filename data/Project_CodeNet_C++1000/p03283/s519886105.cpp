#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<tuple>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int N, M, Q;
vector<vector<int>>sum;
int buildSumTable(vector<int> L, vector<int> R) {
	sum = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	rep(i, M)sum[L[i]][R[i]] ++;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] += sum[i - 1][j];
			sum[i][j] += sum[i][j - 1];
			sum[i][j] -= sum[i - 1][j - 1];
		}
	}
}
int getSumRange(int L, int R) {
	int ans = sum[R][R] - sum[R][L - 1] - sum[L - 1][R] + sum[L - 1][L - 1];
	return ans;
}

int main() {
	cin >> N >> M >> Q;
	vector<int>L(M), R(M);
	rep(i, M)cin >> L[i] >> R[i];
	vector<int>p(Q), q(Q);
	rep(i, Q) cin >> p[i] >> q[i];
	buildSumTable(L, R);
	rep(i, Q) {
		int ans = getSumRange(p[i], q[i]);
		cout << ans << endl;
	}
	return 0;
}
