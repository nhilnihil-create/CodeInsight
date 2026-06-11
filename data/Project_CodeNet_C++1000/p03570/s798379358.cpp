#include<bits/stdc++.h>
using namespace std;
#define N 200005
char s[N];
int a[N],f[N],g[(1<<26)+5];
int len;
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
	  a[i]=a[i-1]^(1<<(s[i]-'a'));
	memset(g,0x3f,sizeof(g));
	memset(f,0x3f,sizeof(f));
	g[0]=f[0]=0;
	for(int i=1;i<=len;i++)
	{
		f[i]=min(f[i],g[a[i]]);
		for(int j=1;j<(1<<26);j<<=1)
		  f[i]=min(f[i],g[a[i]^j]);
		f[i]++;
		g[a[i]]=min(g[a[i]],f[i]);
	}
	printf("%d",f[len]);
	return 0;
}