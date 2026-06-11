#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=400005;
int n,m,l,Flag[N],tot,zz[N],fi[N],ne[N],flag[N][2],f[N],g[N],x[N],y[N];
char s[N];
void down(int x){
	int i=x;
	if (x*2<=l&&flag[f[x*2]][0]*flag[f[x*2]][1]<flag[f[i]][0]*flag[f[i]][1])i=x*2;
	if (x*2<l&&flag[f[x*2+1]][0]*flag[f[x*2+1]][1]<flag[f[i]][0]*flag[f[i]][1])i=x*2+1;
	if (i!=x){
		swap(f[x],f[i]);
		swap(g[f[x]],g[f[i]]);
		down(i);
	}
}
void up(int x){
	if (x==1)return;
	if (flag[f[x]][0]*flag[f[x]][1]<flag[f[x/2]][0]*flag[f[x/2]][1]){
		swap(f[x],f[x/2]);
		swap(g[f[x]],g[f[x/2]]);
		up(x/2);
	}
}
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		flag[x[i]][s[y[i]]-'A']++;
		flag[y[i]][s[x[i]]-'A']++;
		jb(x[i],y[i]);jb(y[i],x[i]);
	}
	for (int i=1;i<=n;i++)f[i]=g[i]=i;
	l=n;
	for (int i=n;i;i--)down(i);
	while (l&&flag[f[1]][0]*flag[f[1]][1]==0){
		int k=f[1];
		Flag[k]=1;
		f[1]=f[l--];
		g[f[1]]=1;
		down(1);
		for (int i=fi[k];i;i=ne[i])
			if (!Flag[zz[i]])flag[zz[i]][s[k]-'A']--,up(g[zz[i]]);
	}
	if (l)puts("Yes");
	else puts("No");
}