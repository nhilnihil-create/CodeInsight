#include <bits/stdc++.h>
using namespace std;
int dp[3005][3005];
int pre[3005][3005];
deque<char> ans;
int main(int argc, char const *argv[])
{
	char s[3005], t[3005];
	scanf("%s%s", &s, &t);
	memset(dp, 0, sizeof dp);
	memset(pre, -1, sizeof pre);
	int slen = strlen(s), tlen = strlen(t);
	for(int i = 0; i < tlen; i++){
		if(s[0] == t[i]) {
			dp[0][i] = 1;
			pre[0][i] = 3;
		}
		else {
			if(i-1 >= 0) {
				dp[0][i] = dp[0][i-1];		
				pre[0][i] = 2;
			}
		}
	}
	for(int i = 0; i < slen; i++){
		if(s[i] == t[0]) {
			dp[i][0] = 1;
			pre[i][0] = 0;
		}
		else {
			if(i-1 >= 0) {
				dp[i][0] = dp[i-1][0];		
				pre[i][0] = 1;
			}
		}
	} 
	for(int i = 1; i < slen; i++){
		for(int j = 1; j < tlen; j++){
			if(s[i] == t[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				pre[i][j] = 3;
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				pre[i][j] = dp[i-1][j] > dp[i][j-1] ? 1 : 2;
			}
		}
	}
	/*
	for(int i = 0; i < slen; i++){
		for(int j = 0; j < tlen; j++){
			printf("%d", pre[i][j]);
		}
		printf("\n");
	}
	*/
	int k = slen - 1, r = tlen - 1;
	while(k >= 0 && r >= 0 && pre[k][r] > 0){
		switch(pre[k][r]){
			case 1:
				k--;
				break;
			case 2:
				r--;
				break;
			case 3:
				ans.push_front(s[k]);
				k--, r--;
				break;
		}
	}
	if(k >= 0 && r >= 0 && pre[k][r] == 0) ans.push_front(s[k]);
	for(auto i : ans) printf("%c", i);
	printf("\n");
	return 0;
}