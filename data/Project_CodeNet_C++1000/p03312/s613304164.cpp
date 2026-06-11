#include <iostream>
#include <cstring>
#include <cmath>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ll long long
ll a[200005];

#define rep(i,a,b) for(int i=a;i<=b;i++)
ll dp[200005];
ll sum[200005];
ll max(ll a,ll b,ll c,ll d)
{
	return max(a,max(b,max(c,d)));
}
ll min(ll a,ll b,ll c,ll d)
{
	return min(a,min(b,min(c,d)));
}
int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);

	rep(i,1,n)scanf("%lld",&a[i]);
	int j=2;
	int k=1;
	rep(i,1,n)
	{
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=1e18;
	rep(mid,2,n)//mid在左边 
	{
	//	cout<<sum[j-1]<<"  "<<sum[mid]-sum[j-1]<<" "<<j<<" "<<(ll)abs(sum[j-1]-(sum[mid]-sum[j-1]))<<" "<<(ll)abs(sum[j]-(sum[mid]-sum[j]))<<endl;
	
		while(j<mid&&((ll)abs(sum[j-1]-(sum[mid]-sum[j-1]))>((ll)abs(sum[j]-(sum[mid]-sum[j])))))
		{
			j++;
		}
		while(k<n-1&&(k<=mid||((ll)abs((sum[n]-sum[k])-(sum[k]-sum[mid])))>((ll)abs((sum[n]-sum[k+1])-(sum[k+1]-sum[mid])))))
		{
			//cout<<k<<" "<<sum[n]-sum[k]<<" "<<sum[k]-sum[mid]<<endl;
			k++;
		}
	//	cout<<mid<<" "<<j<<" "<<k<<endl;
		ll mx=max(sum[j-1],sum[mid]-sum[j-1],sum[n]-sum[k],sum[k]-sum[mid]);
		ll mn=min(sum[j-1],sum[mid]-sum[j-1],sum[n]-sum[k],sum[k]-sum[mid]);
		ans=min(ans,mx-mn);
	}
	cout<<ans;
	return 0;
}