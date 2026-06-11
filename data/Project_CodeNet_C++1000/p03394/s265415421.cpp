#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define pll pair<long,long>
#define INF 10000000000000000
typedef long long ll;
#define PI 3.14159265



int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
	ll n;
	cin>>n;
	if(n==3)
	{
		cout<<"2 5 63";
		
	}
	else
	{
		cout<<"3 9 ";
		ll val=6;
		n-=2;
		for(ll i=2;i<=30000;i+=6)
		{
			cout<<i<<" "<<i+2<<" ";
			n-=2;
			if(n<=1)
				break;
			
		}
		if(n>1)
		{
			for(ll i=15;i<=30000;i+=12)
			{
				cout<<i<<" "<<i+6<<" ";
				n-=2;
				if(n<=1)
					break;
			}
		}
		while(n)
		{
			cout<<val<<" ";
			val+=6;
			n--;
		}
		
	}
	
}				
					
					
