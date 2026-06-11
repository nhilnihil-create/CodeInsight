#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAXNUM = 100000;

int main() {
	int n;
	cin >> n;
	int cnt[2][MAXNUM+1];
	rep(i,2) rep(j,MAXNUM+1) cnt[i][j] = 0;
	rep(i,n) {
		int v;
		cin >> v;
		cnt[i%2][v]++;	
	}
	int max_idx[2] = {0,0};
	int next_max_idx[2] = {0,0};
	int ans = 0;
	rep(i,2) rep(j,MAXNUM+1) if (cnt[i][j] >= cnt[i][max_idx[i]]) max_idx[i] = j;
	rep(i,2) rep(j,MAXNUM+1) if ((cnt[i][j] >= cnt[i][next_max_idx[i]]) && (j != max_idx[i])) next_max_idx[i] = j;
	//sort(cnt[0].begin(), cnt[0].end(), greater<int>());
	//sort(cnt[1].begin(), cnt[1].end(), greater<int>());
	if (max_idx[0] != max_idx[1]) {
		ans = n - cnt[0][max_idx[0]] - cnt[1][max_idx[1]];
		//ans = n - cnt[0][0] - cnt[1][0];
	}
	else {
		ans = min(n - cnt[0][next_max_idx[0]] - cnt[1][max_idx[1]], n - cnt[0][max_idx[0]] - cnt[1][next_max_idx[1]]);
		//ans = min(n - cnt[0][1] - cnt[1][0], n - cnt[0][0] - cnt[1][1]);
	}

	cout << ans << endl;
	return 0;
}
