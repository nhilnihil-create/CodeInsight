#include<cstdio>
#include<iostream>
using namespace std;
int n,k,a[262144],f[262144],g[262144],x[262144],y[262144];
int main(){
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++){
		scanf("%d",&a[i]);
		f[i]=a[i]; x[i]=i; y[i]=-1;
	}
	for(int S=0;S<(1<<n);S++){
		for(int j=0;j<=18;j++){
			if(S&(1<<j)){
				if(f[S^(1<<j)]>f[S]&&x[S^(1<<j)]!=x[S]&&x[S^(1<<j)]!=y[S]) g[S]=f[S],f[S]=f[S^(1<<j)],y[S]=x[S],x[S]=x[S^(1<<j)];
				else if(f[S^(1<<j)]>g[S]&&x[S^(1<<j)]!=x[S]&&x[S^(1<<j)]!=y[S]) g[S]=f[S^(1<<j)],y[S]=x[S^(1<<j)];
				if(g[S^(1<<j)]>f[S]&&y[S^(1<<j)]!=x[S]&&y[S^(1<<j)]!=y[S]) g[S]=f[S],f[S]=g[S^(1<<j)],y[S]=x[S],x[S]=y[S^(1<<j)];
				else if(g[S^(1<<j)]>g[S]&&y[S^(1<<j)]!=x[S]&&y[S^(1<<j)]!=y[S]) g[S]=g[S^(1<<j)],y[S]=y[S^(1<<j)];
			}
		}
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++){
		ans=max(ans,f[i]+g[i]);
		printf("%d\n",ans);
	}
	return 0;
}