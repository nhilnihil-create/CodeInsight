#include <cstdio>
#include <cstring>

inline void chkmax(int& a,int b){
	if(a<b) a=b;
}

const int N=305;

char s[N];

int lim,n,f[N][N][N];

int main(){
	scanf("%s%d",s+1,&lim); n=strlen(s+1);
	for(int i=1;i<=n;++i) for(int k=0;k<=lim;++k) f[i][i][k]=1;
	for(int i=n;i>=1;--i){
		for(int j=i+1;j<=n;++j){
			for(int k=0;k<=lim;++k){
				if(k) chkmax(f[i][j][k],f[i][j][k-1]);
				chkmax(f[i][j][k],f[i][j-1][k]);
				chkmax(f[i][j][k],f[i+1][j][k]);
				if(s[i]==s[j]) chkmax(f[i][j][k],f[i+1][j-1][k]+2);
				else if(k) chkmax(f[i][j][k],f[i+1][j-1][k-1]+2);
			}
		}
	}
	printf("%d\n",f[1][n][lim]); return 0;
}