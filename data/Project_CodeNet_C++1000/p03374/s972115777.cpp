#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll x[100005]={0};
ll v[100005]={0};
ll sum1[100005]={0};
ll sum2[100005]={0};
ll shun[100005]={0};
ll ni[100005]={0};
int main()
{
    ll c;
    int n;
    scanf("%d%lld",&n,&c);
    for(int i=1;i<=n;i++){
    	scanf("%lld%lld",&x[i],&v[i]);
    	sum1[i]=sum1[i-1]+v[i];
    	shun[i]=max(shun[i-1],sum1[i]-x[i]);
	}
	ll maxn=shun[n];
	for(int i=n;i>0;i--){
		sum2[i]=sum2[i+1]+v[i];
		ni[i]=max(ni[i+1],sum2[i]-c+x[i]);
	}
	maxn=max(maxn,ni[1]);
	for(int i=1;i<=n;i++){
		maxn=max(maxn,sum1[i]-2*x[i]+ni[i+1]);
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,sum2[i]-2*(c-x[i])+shun[i-1]);
	}
	printf("%lld\n",maxn);
	/*for(int i=1;i<=n;i++){
        cout<<shun[i]<<endl;
        cout<<ni[i]<<endl;
     }*/
    return 0;
}