#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
const int MaxN = 2e5;
using namespace std;
char s[MaxN + 5];
int dp[1 << 26], f[MaxN + 5], a[MaxN + 5];
int main() 
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	a[0] = 0;
	for (int i = 1; i <= len; i++) a[i] = a[i - 1] ^ (1 << (s[i] - 'a'));
	dp[0] = 0;
	for (int i = 1; i < (1 << 26); i++) dp[i] = 1 << 30;
	for (int i = 1; i <= len; i++) f[i] = 1 << 30;
	for (int i = 1; i <= len; i++) {
		for (int bit = -1; bit <= 25; bit++) {
			int now = a[i];
			if(bit >= 0) {
				now ^= (1 << bit);
			}
			f[i] = min(f[i], dp[now] + 1);
		}
		dp[a[i]] = min(dp[a[i]], f[i]);
	}
	printf("%d\n", f[len]);
}