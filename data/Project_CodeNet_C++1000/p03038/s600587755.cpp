#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	pair<ll,ll>vind[m];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<m;i++)
		cin>>vind[i].second>>vind[i].first;
	sort(vind,vind+m,greater<pair<ll,ll>>());
	//ll sum[n];
	//sum[0]=arr[0];
	/*for(int i=1;i<n;i++)
	{
		//sum[i]=arr[i]+sum[i-1];
	}*/
	ll k=0;
	for(ll i=0;i<m;i++)
	{
		ll j=0;
		for(j=k;j<min(k+vind[i].second,n);j++)
		{
			if(arr[j]<vind[i].first)
			{
				arr[j]=vind[i].first;
			}
			else if(vind[i].first<=arr[j])
			{
				k=n;
				break;		
			}
		}
		if(k==n)
			break;
		
			k=k+vind[i].second;
	}
	ll sum=0;
	for(int i=0;i<n;i++)
		sum += arr[i];
	cout<<sum<<"\n";
}
