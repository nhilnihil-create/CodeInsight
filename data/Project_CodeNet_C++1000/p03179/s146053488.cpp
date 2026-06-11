#include<cstdio>
const int N=3003,M=1e9+7;
inline int Mod(int a){return a<M?a:a-M;}
int n,f[N][N];char a[N];
signed main(){
	scanf("%d%s",&n,a+2);
	f[1][1]=1;
	for(int i=2;i<=n;i++)
	  for(int j=1;j<=i;j++){
		if(a[i]=='<')f[i][j]=Mod(f[i][j-1]+f[i-1][j-1]);
		if(a[i]=='>')f[i][j]=Mod(f[i][j-1]+Mod(f[i-1][i-1]-f[i-1][j-1]+M));
	  }printf("%d",f[n][n]);
	return 0;
}