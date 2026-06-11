#include<bits/stdc++.h>
#define rg register
using namespace std;

const int N = 300+10;
char str[N];
int k,n;
int f[N][N][N];


int ck(int x,int y){
	if(x!=y && str[x]==str[y]) return 2;
	if(x==y) return 1;
	return 0;
}

int main(){
	//freopen("d.in","r",stdin);
	//freopen("d.out","w",stdout);
	scanf("%s",str+1);		
	n=strlen(str+1);
	scanf("%d",&k);

	int ans=0;
	for(int i=1; i<=n; ++i)
		for(int j=n; j>=i; --j)
			for(int t=0; t<=k; ++t){
				int x=i+1,y=j-1,c=(bool)(str[i]!=str[j]);
					if(x<=y&&t+c<=k) f[t+c][x][y]=max(f[t+c][x][y],f[t][i][j]+2);
					if(x-1==y){
						if(t+c<=k) ans=max(ans,f[t][i][j]+2);
					}
					if(x-2==y){
						if(t+c<=k) ans=max(ans,f[t][i][j]+1);
					}

					f[t][x][y]=max(f[t][x][y],f[t][i][j]);
					f[t][i][y]=max(f[t][i][y],f[t][i][j]);
					f[t][x][j]=max(f[t][x][j],f[t][i][j]);
					ans=max(ans,f[t][i][j]);
			}

	printf("%d\n",ans);
}