#include<cstdio>
#include<algorithm>
#include<cstring>
#define MN 305
using namespace std;
int k,f[MN][MN][MN];char ch[MN];
int main(){
	scanf("%s",ch+1);int n=strlen(ch+1);scanf("%d",&k);
	for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)f[i][i][j]=1;
	for(int len=2;len<=n;len++)
		for(int i=1,j=i+len-1;j<=n;i++,j++)
          	for(int kk=0;kk<=k;kk++){
            	f[i][j][kk]=max(f[i+1][j][kk],f[i][j-1][kk]);
            	if(kk>0)f[i][j][kk]=max(f[i][j][kk],f[i+1][j-1][kk-1]+2);
            	if(ch[i]==ch[j])f[i][j][kk]=max(f[i][j][kk],f[i+1][j-1][kk]+2);
          	}
	printf("%d\n",f[1][n][k]);
}