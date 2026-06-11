#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,aa,bb,i,j,ans,f[5001][5001],a[5001],la;
int main(){
	scanf("%lld%lld%lld",&n,&aa,&bb);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=0;i<=n;i++)
	 for(j=0;j<=n;j++)f[i][j]=1e16;
	f[0][0]=0;
	for(i=1;i<=n;i++)
	 for(j=0;j<=n;j++){
	 	la=f[i-1][j];
	 	if(la==1e16)continue;
	 	if(a[i]>j){
	 		f[i][j]=min(f[i][j],la+aa);
	 		f[i][a[i]]=min(f[i][a[i]],la);
	 	}
	 	 else f[i][j]=min(f[i][j],la+bb);
	 }
	 ans=1e16;
	 for(i=0;i<=n;i++)ans=min(ans,f[n][i]);
	 printf("%lld",ans);
}