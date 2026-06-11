#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=200010;
ll x[maxn],c[maxn],sum_x[maxn];
int main(){
	int n;
	ll X;
	scanf("%d%lld",&n,&X);
	for(int i=1;i<=n;i++){
		scanf("%lld",x+i);
		sum_x[i]=sum_x[i-1]+x[i];
	}
	c[1]=c[2]=5;
	for(int i=3;i<=n;i++)
		c[i]=c[i-1]+2;
	ll ans=8000000000000000000ll;
	for(int k=1;k<=n;k++){
		ll cost=k*X;
		for(int i=n,j=1;i>0 && cost<ans;i=max(i-k,0),j++)
			cost+=c[j]*(sum_x[i]-sum_x[max(i-k,0)]);
		ans=min(ans,cost);
	}
	printf("%lld\n",ans+n*X);
	return 0;
}