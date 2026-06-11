#include<bits/stdc++.h>
using namespace std;

#define MAX 310

int dp[MAX][MAX][MAX]; //l,r,change
char buf[MAX];
string s;
int k;


int main(){
	scanf("%s", buf);
	s = buf;
	scanf("%d", &k);
	int n = strlen(buf);
	int ans = 0;
	for (int chang = 0; chang <= k; chang++){
		for (int len = n; len >=0; len--){
			for (int i = 0; i < n; i++){
				int j = i + len;
				if (j < 0 || j >= n)continue;
				//match
				dp[i + 1][j][chang] = max(dp[i + 1][j][chang], dp[i][j][chang]);
				if (j){
					dp[i][j - 1][chang] = max(dp[i][j - 1][chang], dp[i][j][chang]);
				}
				if (s[i] == s[j]){
					int ii = i + 1;
					int jj = j - 1;
					ans = max(ans, (dp[i][j][chang] + 1)*2-(int)(i==j) );
					if (ii < n&&jj >= 0){
						dp[ii][jj][chang] = max(dp[ii][jj][chang], dp[i][j][chang] + 1);
					}
				}
				else{
					if (chang < k){
						int ii = i + 1;
						int jj = j - 1;
						ans = max(ans, (dp[i][j][chang] + 1) * 2 - (int)(i == j));
						if (ii < n&&jj >= 0){
							dp[ii][jj][chang + 1] = max(dp[ii][jj][chang + 1], dp[i][j][chang] + 1);
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}