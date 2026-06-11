#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5,mod=1e9+7;
int n,cnt,f[maxn],c[maxn],vis[maxn],pre[maxn];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&c[i]);}
	for(int i=1;i<=n;i++){
		if(c[i]!=c[i-1]){cnt++;}
		c[cnt]=c[i];
	}
	for(int i=1;i<=cnt;i++){
		pre[i]=vis[c[i]];
		vis[c[i]]=i;
	}
	f[0]=1;
	for(int i=1;i<=cnt;i++){
		f[i]=f[i-1];
		if(pre[i]){f[i]=(f[i]+f[pre[i]])%mod;}
	}
	printf("%d\n",f[cnt]);
	return 0;
} 