	#include <bits/stdc++.h>
	using namespace std;
	#define mod 1000000007
	#define fi first
	#define se second
	#define mp make_pair
	#define pb push_back
	#define ps push
	#define pll pair<long,long>
	typedef long long ll;
	#define PI 3.14159265
	
	
	const ll INF=(ll)1e16;
	
	
	int main()
	{
		ios::sync_with_stdio(0); 
		cin.tie(0); 
		cout.tie(0);
		
		ll n,k;
		cin>>n>>k;
		if(n==1)
		{
			if(k==0)
				{
					cout<<"0 0 1 1";
				}
			else
				{
					cout<<-1;
				}
				exit(0);
			
		}
		else if(k>=(1<<n))
		{
			cout<<-1;
			exit(0);
		
		}
		cout<<k<<" ";
		vector<ll> v;
		for(ll i=0;i<(1<<n);i++)
		{
			if(i==k)
				continue;
			cout<<i<<" ";
			v.pb(i);
		}
		cout<<k<<" ";
		reverse(v.begin(),v.end());
		for(auto i:v)
		{
			cout<<i<<" ";
		}
	}		
