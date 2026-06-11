#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 3;
double dp[MAXN][MAXN][MAXN];
int cnt[3];
int n;

void input();
void solve();

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	input();
	solve();
	return 0;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1)
			cnt[0]++;
		else if (a == 2)
			cnt[1]++;
		else
			cnt[2]++;
	}
}

void solve() {
	for (int i = 0; i <= 300; i++)
		for (int j = 0; i + j <= 300; j++)
			for (int k = 0; i + j + k <= 300; k++) {
				if (i)
					dp[i][j][k] = 1ll * i * dp[i - 1][j + 1][k];
				if (j)
					dp[i][j][k] += 1ll * j * dp[i][j - 1][k + 1];
				if (k)
					dp[i][j][k] += 1ll * k * dp[i][j][k - 1];
				if (i + j + k) {
					dp[i][j][k] += n;
					dp[i][j][k] /= i + j + k;
				}
			}
	cout.precision(10);
	cout << fixed << dp[cnt[2]][cnt[1]][cnt[0]] << endl;
}
