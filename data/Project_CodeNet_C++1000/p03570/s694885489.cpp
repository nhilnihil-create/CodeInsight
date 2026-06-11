#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int inf=1e8;
int f[1<<26],a[200011],dp[200011];
char s[200011];
int main(){
	memset(f,127,sizeof(f));
	memset(dp,127,sizeof(dp));
	f[0]=0;
	scanf("%s",s);
	int len=strlen(s);
	a[0]=(1<<(s[0]-'a'));
	for(int i=1;i<len;i++) a[i]=a[i-1]^(1<<(s[i]-'a'));
	for(int i=0;i<len;i++){
		for(int j=0;j<26;j++) if(f[a[i]^(1<<j)]<inf) dp[i]=min(dp[i],f[a[i]^(1<<j)]+1);
		if(!a[i]) dp[i]=min(dp[i],1);
		if(dp[i]<inf) f[a[i]]=min(f[a[i]],dp[i]);
	}
	printf("%d\n",dp[len-1]);
	return 0;
}