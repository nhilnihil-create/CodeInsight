#include<cstdio>
#include<cstring>
#define MN 300
char s[MN+5];
int ls[MN+5][26],f[MN+5][MN+5][MN+5];
inline void rw(int&a,int b){if(b>a)a=b;}
int main()
{
	int n,m,i,j,k,ans=0;
	scanf("%s%d",s+1,&m);n=strlen(s+1);
	for(i=1;i<=n;++i)
	{
		for(j=0;j<26;++j)ls[i][j]=ls[i-1][j];
		ls[i][s[i]-'a']=i;
	}
	for(i=1;i<=n;++i)for(j=n;j>=i;--j)for(k=0;k<=m;++k)
	{
		rw(f[i+1][j][k],f[i][j][k]);
		if(ls[j][s[i]-'a']>i)rw(f[i+1][ls[j][s[i]-'a']-1][k],f[i][j][k]+2),rw(ans,f[i][j][k]+2);
		rw(ans,f[i][j][k]+1);
		if(i<j&&k<m)rw(f[i+1][j-1][k+1],f[i][j][k]+2),rw(ans,f[i][j][k]+2);
	}
	printf("%d",ans);
}