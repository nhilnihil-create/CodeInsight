#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int ABC=26;
const int maxn=2e5+2;
const int maxm=1<<ABC;
const int INF=0x3f3f3f3f;
int len,bit=0;
char str[maxn];
int dp[maxm];
int change(char ch){return ch-'a';}
void DP(){
	dp[0]=0;
	for (int i=1;i<(1<<ABC);i++) dp[i]=INF;
	for (int i=1;i<=len;i++){
		bit^=(1<<(str[i]-'a'));
		for (int j=0;j<26;j++) dp[bit]=min(dp[bit],dp[bit^(1<<j)]+1);
	}
}
int main(){
	scanf("%s",str+1);
	len=strlen(str+1);
	DP();
	printf("%d",max(1,dp[bit]));
	return 0;
}