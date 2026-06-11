#include <bits/stdc++.h>
using namespace std;

const int maxN = 200010;
const int INF = 0x3f3f3f3f;

int A[maxN];
char str[maxN];
int dp[maxN][27];
int mp[1 << 26];

int main (){
	int n, i, j, s;
	scanf("%s", str);
	memset(dp, INF, sizeof dp);
	memset(mp, INF, sizeof mp);
	for(i = 0; str[i]; ++i) A[i] = str[i] - 'a'; n = i;
	s = (1 << A[0]);
	mp[0] = 0;
	mp[s] = dp[0][A[0]] = 1;
	for(i = 1; i < n; ++i){
		int bs = s;
		//printf("#%d ", i);
		s ^= (1 << A[i]);
		//printf("bs = %d s = %d\n", bs, s);
		for(j = 0; j < 26; ++j){
			if(j == A[i]) dp[i][j] = dp[i - 1][26];
			dp[i][j] = mp[bs ^ (1 << j) ^ (1 << A[i])] + 1;
		}
		dp[i][26] = dp[i - 1][A[i]];
		for(j = 0; j <= 26; ++j)
			mp[s] = min(mp[s], dp[i][j]);
	}
	int ans = INF;
	for(i = 0; i <= 26; ++i) ans = min(ans, dp[n - 1][i]);
	printf("%d\n", ans);
	return 0;
}
