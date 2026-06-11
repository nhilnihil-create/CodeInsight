#include<bits/stdc++.h>
#define maxn 1005
#define mod 1000000007 
using namespace std;

unsigned int n,m,p[maxn][maxn],f[maxn][maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='.') p[i][j+1]=1;
		}
	}
//	for(int i=1;i<=n;i++){ for(int j=1;j<=m;j++){ printf("%d ",p[i][j]); } printf("\n"); }
	f[1][1]=1;
	for(int i=2;i<=n;i++){
		if(p[i][1]) f[i][1]=f[i-1][1];
		else break;
	}
	for(int i=2;i<=m;i++){
		if(p[1][i]) f[1][i]=f[1][i-1];
		else break;
	}
//	for(int i=1;i<=n;i++){ for(int j=1;j<=m;j++){ printf("%d ",f[i][j]); } printf("\n"); }
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(p[i][j]) {
				f[i][j]=f[i-1][j]+f[i][j-1];
				f[i][j]%=mod;
			}
		}
	}
	
	printf("%d\n",f[n][m]%mod);
} 
