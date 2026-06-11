#include<iostream>
#include<cstdio>
#include<cstring>
using std::min;

const int MAXN=2e5+5;

int n;char s[MAXN];
int a[MAXN],f[MAXN],minv[1<<26];

int main()
{
	int i,k;
	scanf("%s",s+1);n=strlen(s+1);
	for(i=1;i<=n;i++) a[i]=a[i-1]^(1<<(s[i]-'a'));
	memset(minv,0x3f,sizeof(minv));minv[0]=0;
	for(i=1;i<=n;i++)
	{
		f[i]=minv[a[i]]+1;
		for(k=0;k<26;k++)
			f[i]=min(f[i],minv[a[i]^(1<<k)]+1);
		minv[a[i]]=min(minv[a[i]],f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}
