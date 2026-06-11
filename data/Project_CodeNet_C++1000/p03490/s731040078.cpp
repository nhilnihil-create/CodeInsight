#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxN = 8005;
bool dp[2][maxN * 2], ok[2];
int tx, ty, N, q[maxN];
char s[maxN];
int main() {
	scanf("%s", s); scanf("%d%d", &tx, &ty);
	int cnt = 0, ed = 0; int len = strlen(s);
	for(int i = 0; i < len; ++i) {
		if(s[i] == 'T') {
			q[++ed] = cnt; cnt = 0;
		} else cnt++;
	}
	if(cnt) q[++ed] = cnt;
	dp[0][q[1] + 8000] = 1; int nw = 0;
	//cout << ed << endl;
	for(int i = 3; i <= ed; i += 2) {
		for(int j = 0; j <= 16000; ++j) {
			if(!dp[nw][j]) continue;
			if(!q[i]) {
				dp[nw ^ 1][j] = 1; dp[nw][j] = 0; continue;
			}
			for(int k = -q[i]; k <= q[i]; k += 2 * q[i]) {
				if(k + j < 0 || k + j > 16000) continue;
				dp[nw ^ 1][k + j] = 1;
			}
			dp[nw][j] = 0;
		}
		nw ^= 1;
	}
	ok[0] = dp[nw][tx + 8000];
	for(int i = 0; i < 2; ++i)
	for(int j = 0; j <= 16000; ++j) dp[i][j] = 0;
	dp[0][8000] = 1; nw = 0;
	for(int i = 2; i <= ed; i += 2) {
		for(int j = 0; j <= 16000; ++j) {
			if(!dp[nw][j]) continue;
			//cout << i << ' ' << j << endl;
			if(!q[i]) {
				dp[nw ^ 1][j] = 1; dp[nw][j] = 0; continue;
			}
			for(int k = -q[i]; k <= q[i]; k += 2 * q[i]) {
				if(k + j < 0 || k + j > 16000) continue;
				dp[nw ^ 1][k + j] = 1;
			}
			dp[nw][j] = 0;
		}
		nw ^= 1;
	}
	ok[1] = dp[nw][ty + 8000];
	if(ok[0] && ok[1]) printf("Yes\n");
	else printf("No\n");
	return 0;
}