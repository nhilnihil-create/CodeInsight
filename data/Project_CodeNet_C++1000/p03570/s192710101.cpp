#include<cstdio>
#include<cstring>
int oo,N,sum,g[67108864],f[200010],x[27],n;
char s[200010];
int min(int a,int b)
{
	if (a<b) return(a);
	return(b);
}
int main()
{
	oo=1000000000;
	scanf("%s",s);
	n=strlen(s);
	N=1<<26;
	for (int i=0;i<N;i++) g[i]=oo;
	g[0]=0;
	for (int i=0;i<26;i++) x[i]=1<<i;
	x[26]=0;
	sum=0;
	for (int i=0;i<n;i++)
	{
		sum=sum^(1<<(s[i]-'a'));
		f[i]=oo;
		for (int j=0;j<=26;j++) f[i]=min(f[i],g[x[j]^sum]+1);
		g[sum]=min(g[sum],f[i]);
	}
	printf("%d\n",f[n-1]);
	return 0;
}