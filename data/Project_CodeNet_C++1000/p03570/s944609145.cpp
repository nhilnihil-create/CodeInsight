#include<cstdio>
#include<iostream>
#include<cstring>
#define chkmin(a,b) a=min(a,b);
using namespace std;
const int maxn=300010;
int n,f[70000000],h[maxn];
char s[maxn];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	memset(f,0x3f,sizeof(f));f[0]=0;
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]^(1<<(s[i]-'a')); 
	for(int i=1;i<=n;i++)
		for(int j=0;j<26;j++)
			chkmin(f[h[i]],f[h[i]^(1<<j)]+1);
	printf("%d",max(1,f[h[n]]));
}