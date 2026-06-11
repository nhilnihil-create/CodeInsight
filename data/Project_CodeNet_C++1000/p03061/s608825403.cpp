#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 100000000
#define mod 1000000007
#define ld long double
#define point complex<long double>
#define pi acos(-1)
#define IO                            \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
ll gcd(ll a,ll b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	//cout<<gcd(12,18)<<endl;
	int n;
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(n==2)
	{
		cout<<max(arr[0],arr[1])<<endl;
		return 0;
	}
	ll pre[n];
	ll suf[n];
	pre[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		pre[i]=gcd(arr[i],pre[i-1]);
	}
	suf[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
	{
		suf[i]=gcd(suf[i+1],arr[i]);
	}
	ll res=1;
	
	res=max(suf[1],pre[n-2]);
	/*cout<<suf[1]<<endl;
	cout<<pre[n-2]<<endl;
	for(auto s:pre)
	{
		cout<<s<<" ";
	}
	cout<<endl;
	for(auto s:suf)
	{
		cout<<s<<" ";
	}
	cout<<endl;*/
	for(int i=1;i<=n-2;i++)
	{
		//cout<<gcd(suf[i+1],pre[i-1])<<endl;
		res=max(res,gcd(suf[i+1],pre[i-1]));
	}
	cout<<res<<endl;

	return 0;
}