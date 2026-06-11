#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,A,B,i,j,ans,l,r,f[5010],mx,a[5010];
int main(){
	scanf("%lld%lld%lld",&n,&A,&B);
	ans=1e18;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);mx=0;
		f[i]=1e18;l=r=0;
		for(j=i-1;j;j--){
			if(a[j]<a[i]&&a[j]>mx)f[i]=min(f[i],f[j]+l*B+r*A);
			if(a[j]>a[i])r++;
			 else l++,mx=max(mx,a[j]);
		}
		if(mx==0)f[i]=r*A;
		for(j=i+1;j<=n;j++)mx=max(mx,a[j]);
		if(mx<a[i])ans=min(ans,f[i]+B*(n-i));
		//printf("%lld\n",f[i]);
	}
	printf("%lld",ans);
}