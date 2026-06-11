#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200000+5;
typedef unsigned long long LL;
int n,x,a[maxn];
LL suf[maxn];
int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];
	LL ans=-1;
	for(int k=1;k<=n;k++){
		LL s=1ll*(n+k)*x;
		int j=n-k+1,t;
		s+=5*suf[j];j-=k;
		for(t=2;j>=1;j-=k,t++)s+=(2*t+1)*(suf[j]-suf[j+k]);
		s+=(2*t+1)*(suf[1]-suf[j+k]);
		if(ans==-1)ans=s;
		else ans=min(ans,s);
	}
	printf("%lld",ans);
	return 0; 
}