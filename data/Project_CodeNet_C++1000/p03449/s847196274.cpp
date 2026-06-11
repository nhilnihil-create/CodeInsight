#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw	 "\n"
#define mod 1000000007


int main(void)
{
	CIN;
	ll tc,l,k=0,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	cin>>n;
	ll arr1[n],arr2[n];
	cin>>arr1[0];
	for(ll i=1;i<n;i++){
		cin>>arr1[i];
		arr1[i]+=arr1[i-1];
	}
	for(ll i=0;i<n;i++)cin>>arr2[i];
	for(ll i=n-2;i>=0;i--)
		arr2[i]+=arr2[i+1];
	for(ll i=0;i<n;i++)
		z=max(z,arr1[i]+arr2[i]);
	cout<<z;
	
}