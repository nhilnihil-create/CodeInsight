#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int a[200001], c[200001], b[200001];
ll dp[200001];
int main() {
	
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin>>a[i];
	c[1] = a[1];
	int tot = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] != c[tot])
			c[++tot] = a[i];

	}                                         ///把连续的相同的数变为一个
	dp[0] = 1;                                ///dp[i]是截止到第i位的结果数
	for (int i = 1; i <= tot; i++) {
		if (b[c[i]])                           ///b[i]是i上一次在c中出现的位置，若i未出现过则b[i]为0
			dp[i] = (dp[i - 1] + dp[b[c[i]]]) % mod;
		else 
			dp[i] = dp[i - 1];
		dp[i] %= mod;
		b[c[i]] = i;

	}
	cout << dp[tot] << endl;
	return 0;

}