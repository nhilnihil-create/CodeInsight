#include<bits/stdc++.h>
#define reg register
#define inf 9982443530000000
#define maxn 5001
#define int long long
using namespace std;
inline int  read() {
    reg int s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
int n, A, B, a[maxn], b[maxn], pos[maxn], ans = inf, dp[maxn][maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n = read(); A = read(); B = read();
	for(int i = 1; i <= n; i++) a[i] = read(), pos[a[i]] = i;
	memset(dp, 0x3f3f3f, sizeof dp);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++)
		{
			if(pos[i] > pos[j]) {
				dp[i][i] = min(dp[i - 1][j], dp[i][i]);
				dp[i][j] = dp[i - 1][j] + B;
			}
			else dp[i][j] = dp[i - 1][j] + A;
		}
	}
	for(int i = 1; i <= n; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}