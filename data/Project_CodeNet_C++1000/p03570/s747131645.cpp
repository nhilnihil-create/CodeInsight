#include<cstdio>
#include<cstring>
int f[200005],s[200005],g[(1<<26)+5]; 
char str[200005];
int min(int x,int y) {return x<y?x:y;}
int main()
{
	scanf("%s",str);memset(g,0x3f,sizeof(g));
	int n=strlen(str);
	for(int i=1;i<=n;i++) s[i]=s[i-1]^(1<<(str[i-1]-'a'));
	g[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=g[s[i]]+1;
		for(int j=0;j<26;j++)
		f[i]=min(f[i],g[s[i]^(1<<j)]+1);
		g[s[i]]=min(g[s[i]],f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}