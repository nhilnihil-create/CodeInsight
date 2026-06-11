#include <stdio.h>
int n,m;
int k[11];
int kn[11];
int sn[11][11];
int s[11][11];
int p[11];
int f(int x){
	int cnt = 0;
	if(x==n+1){
		for(int i=1;i<=m;i++){
			if(p[i]==1) return 0;
		}
		return 1;
	}
	for(int i=1;i<=kn[x];i++){
		p[sn[x][i]] = (p[sn[x][i]]+1)%2;
	}
	cnt += f(x+1);
	for(int i=1;i<=kn[x];i++){
		p[sn[x][i]] = (p[sn[x][i]]+1)%2;
	}
	cnt += f(x+1);
	return cnt;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d",&s[i][j]);
			kn[s[i][j]]++;
			sn[s[i][j]][kn[s[i][j]]] = i;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
	}
	printf("%d\n",f(1));
}