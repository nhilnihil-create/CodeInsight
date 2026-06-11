#include<bits/stdc++.h>
using namespace std;
const int maxn = 3000+5;
int dp[maxn][maxn];
int pre[maxn][maxn];
int sL, tL;
string s, t;


void LCS() {
	memset(dp, 0, sizeof(dp));

	for(int i= 0; i<sL; i++){
		for(int j=0; j<tL; j++){
			if(s[i] == t[j]){
				dp[i+1][j+1] = dp[i][j] + 1;
				pre[i+1][j+1] = 3;
			}
			else{
				if(dp[i][j+1] > dp[i+1][j]){
					dp[i+1][j+1] = dp[i][j+1];
					pre[i+1][j+1] = 1;//上
				}
				else{
					dp[i+1][j+1] = dp[i+1][j];
					pre[i+1][j+1] = 2;
				}
			}
		}
	}
}

void print_LCS(int x, int y) {
	if(x==0 || y==0) return;
	if(pre[x][y] == 3){
		print_LCS(x-1, y-1);
		cout << s[x-1];
	}
	else if(pre[x][y] == 1){
		print_LCS(x-1, y);
	}
	else if(pre[x][y] == 2){
		print_LCS(x, y-1);
	}
}





int main(int argc, char const *argv[])
{
	while(getline(cin, s)) {
		getline(cin, t);
		memset(pre, 0, sizeof(pre));
		sL = s.length();
		tL = t.length();
		LCS();
		print_LCS(sL, tL);
		cout << endl;
	} 
	return 0;
}