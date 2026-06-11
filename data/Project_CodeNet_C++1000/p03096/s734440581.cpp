#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){ if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int n,c[200100],b[200100],tail,f[200100],sum[200100];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		c[i]=read();
		if(c[i]!=c[i-1]) b[++tail]=c[i];
	}
	f[0]=1;
	for(int i=1;i<=tail;++i){
		(f[i]+=(sum[b[i]]+f[i-1])%mod)%=mod;
	//	cout<<i<<' '<<f[i]<<' '<<sum[b[i]]<<endl;
		sum[b[i]]=(sum[b[i]]+f[i-1])%mod;
	}
	printf("%d\n",f[tail]);
	return 0;
}
