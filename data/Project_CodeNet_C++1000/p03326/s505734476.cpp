#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MIN = -1e16;
int plm[] = {1, -1};

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<ll>> xyz(N, vector<ll>(3));
	for(int i=0;i<N;i++) {
		cin >> xyz[i][0] >> xyz[i][1] >> xyz[i][2];
	}
	
	vector<vector<vector<ll> > > dp(N+1, vector<vector<ll> >(M+1, vector<ll>(8, MIN)));
	for(int i=0;i<=N;i++)
		for(int j=0;j<8;j++)
			dp[i][0][j] = 0;

	for(int i=1;i<=N;i++) {
		for(int m=1;m<=M;m++) {
			int cnt = 0;
			for(int j=0;j<2;j++) {
				for(int k=0;k<2;k++) {
					for(int l=0;l<2;l++) {
						dp[i][m][cnt] = max(dp[i-1][m][cnt] ,dp[i-1][m-1][cnt] + plm[j] * xyz[i-1][0] + plm[k] * xyz[i-1][1] + plm[l] * xyz[i-1][2]);
						cnt++;
					}
				}
			}
		}
	}
	ll ans = LLONG_MIN;
	for(int i=0;i<8;i++) {
		ans = max(ans, dp[N][M][i]);
	}
	cout << ans << endl;
}