#include <cstdio>
#include <algorithm>
#include <cstring>

using std::min;

const int MAXN=2e5+5,MAXSTA=1<<26;
int n;
int xor_sum[MAXN];
char s[MAXN];

inline int DP(){
	static int sta[MAXSTA],dp[MAXN];
	memset(sta,0x3f,sizeof(sta));
	sta[0]=0;
	for(int i=1;i<=n;++i){
		dp[i]=sta[xor_sum[i]]+1;
		for(int j=0;j<26;++j)
			dp[i]=min(dp[i],sta[xor_sum[i]^1<<j]+1);
		sta[xor_sum[i]]=min(sta[xor_sum[i]],dp[i]);
	}
	return dp[n];
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
		xor_sum[i]=xor_sum[i-1]^1<<s[i]-'a';
	printf("%d",DP());
	return 0;
}