#include<cstdio>
#include<cstring>
#define reg register
#define max(a,b) (a>b?a:b)
typedef long long ll;
int f[305][305][305];
char ch[305];
int main(){
	scanf("%s",ch+1);
	reg int k,n=strlen(ch+1),ans=0;scanf("%d",&k);
	for(reg int i=1;i<=n;i++)
		for(reg int j=0;j<=k;j++)
			f[i][i][j]=1;
	for(reg int l=1;l<n;l++)
		for(reg int i=1,j=i+l;j<=n;i++,j++)
			for(reg int s=0;s<=k;s++){
				f[i][j][s]=max(f[i+1][j][s],f[i][j-1][s]);
				if(ch[i]==ch[j])f[i][j][s]=max(f[i][j][s],f[i+1][j-1][s]+2);
				if(s>0)f[i][j][s]=max(f[i][j][s],f[i+1][j-1][s-1]+2);
			}
	for(reg int i=0;i<=k;i++)ans=max(ans,f[1][n][i]);
	printf("%d\n",ans);
	return 0;
}