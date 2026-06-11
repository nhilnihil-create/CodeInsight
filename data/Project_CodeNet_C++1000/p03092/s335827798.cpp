#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
ll f[5010][5010],n,A,B,p[5010];
int main(){
	read(n);read(A);read(B);
	for(int i=1;i<=n;i++) read(p[i]);
	memset(f,63,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][p[i]]=(i-1)*A;
		for(int j=1;j<=n;j++){
			f[i][j]=min(f[i][j],f[i-1][j]+(p[i]>j?A:B));
			if(j<p[i]) f[i][p[i]]=min(f[i][p[i]],f[i-1][j]);
		}
	}
	ll ans=1e18;
	for(int i=1;i<=n;i++) ans=min(ans,f[n][i]);
	cout<<ans<<'\n';
	return 0;
}
