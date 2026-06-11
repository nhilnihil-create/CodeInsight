// CODE © by 𝕌𝕥𝕜𝕒𝕣𝕤𝕙 𝔾𝕒𝕣𝕘
// Copying or sharing of this code without permission of the Author is strictly prohibited!!!
#include <bits/stdc++.h>
using namespace std;
#define Speed ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define endl "\n"
int power(int x, int n, int mod) {int res = 1; x %= mod; while (n) {if (n & 1)res = (res * x) % mod; x = (x * x) % mod; n >>= 1;} return res;}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int a = 0, b = 0, c = 0, d = 0, i = 0, j = 0, k = 0, t = 0, n = 0, q = 0;
	cin >> n;
	int arr[n + 1], sus[4]={0};
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sus[arr[i]]++;
	}
	int ms1=0, ms2=0, ms3=0;
	ms1 = sus[1] + sus[2] + sus[3];
	ms2 = sus[2] + sus[3];
	ms3 = sus[3];
	double dp[ms3+1][ms2+1][ms1+1];
	for (int i = 0; i <= ms3; i++)
		for (int j = 0; j <= ms2; j++)
			for (int k = 0; k <= ms1; k++)
				dp[i][j][k]= 0.0;
	for (int i = 0; i <= ms3; i++)
		for (int j = 0; j <= ms2-i; j++)
			for (int k = 0;k <= ms1-i-j; k++) {
				if (i == 0 && j == 0 && k == 0)continue;
				dp[i][j][k] = (n * 1.0) / (i + j + k);
				if (k > 0)dp[i][j][k] += (dp[i][j][k - 1] * k * 1.0) / (i + j + k);
				if (j > 0)dp[i][j][k] += (dp[i][j - 1][k + 1] * j * 1.0) / (i + j + k);
				if (i > 0)dp[i][j][k] += (dp[i - 1][j + 1][k] * i * 1.0) / (i + j + k);
			}
	cout <<fixed<<setprecision(10)<< dp[sus[3]][sus[2]][sus[1]] ;

}