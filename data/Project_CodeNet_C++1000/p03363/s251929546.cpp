#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,x,ans,sum;
map<ll,ll>mp;
int main(){
	scanf("%lld",&n);
	mp[0]++;
	for(i=1;i<=n;i++){
		scanf("%lld",&x);
		sum+=x;
		ans+=mp[sum];mp[sum]++;
	}
	printf("%lld",ans);
}