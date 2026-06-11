#include <bits/stdc++.h>
using namespace std;

map<int, int> dp;
char s[200005];
bool vis[26];

int main(){
	scanf("%s", s);
	int l = strlen(s);
	dp[0] = 0;
	for(int i=0;i<l;i++){
		int c = s[i]-'a';
		vis[c] = 1-vis[c];

		int val = 0;
		for(int j=0;j<26;j++) if(vis[j]) val+=(1<<j);

		int ans = i+1;

		for(int j=0;j<26;j++){
			if(dp.count(val^(1<<j))){
				ans = min(ans, dp[val^(1<<j)]+1);
			}
		}
		if(dp.count(val)) ans = min(ans, dp[val]+1), dp[val] = min(dp[val], ans);
		else dp[val] = ans;

		if(i == l-1) printf("%d\n", ans);
	}
}