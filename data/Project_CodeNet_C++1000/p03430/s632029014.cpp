#include <bits/stdc++.h>
using namespace std;
const int N = 305;
char s[N];
int n, K;
int f[N][N][N];
int Dp(int l, int r, int x) {
	if (l > r) return 0;
	if (l == r) return 1;
	int &ans = f[l][r][x];
	if (~ ans) return ans;
	if (s[l] == s[r]) return ans = 2 + Dp(l+1, r-1, x);
	ans = Dp(l+1, r, x);
	ans = max(ans, Dp(l, r-1, x));
	if (x) ans = max(ans, 2 + Dp(l+1, r-1, x-1));
	return ans;
}
int main() {
	scanf("%s", s+1);
	n = strlen(s+1);
	cin >> K;
	memset(f, -1, sizeof f);
	cout << Dp(1, n, K) << endl;
	return 0;
}