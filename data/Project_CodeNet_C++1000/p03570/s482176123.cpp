#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int mx[1 << 26],dp[200005],cnt[26],i,j,n;
char s[200005];

int main(){
	scanf("%s", s);
	
	n = strlen(s);
	int cur = 0;
	
	for(i = 0; i < n; i++)
	dp[i] = INF;
	for(i = 1; i < (1 << 26); i++)
	mx[i] = INF;
	
	for(i = 0; i < n; i++){
		cnt[s[i] - 'a']++;
		if(cnt[s[i] - 'a'] & 1)
		cur += (1 << (s[i] - 'a'));
		else
		cur -= (1 << (s[i] - 'a'));
		
		int mask = cur ^ 0;
		
		dp[i] = min(dp[i], mx[mask] + 1);
		for(j = 0; j < 26; j++){
			mask = cur ^ (1 << j);
			dp[i] = min(dp[i], mx[mask] + 1);
		}
		
		mx[cur] = min(mx[cur], dp[i]);
	}
	
	printf("%d\n", dp[n - 1]);
}
