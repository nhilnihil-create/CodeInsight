#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979
#define EPS 1e-8
#define mod 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl "\n"
	 
const ll INF=(ll)2e18;
		
		
const int N=2e5+5;
		
		
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
				
	ll n;
	cin>>n;
	string s;
	cin>>s;
	
	ll q;
	cin>>q;
	
	while(q)
	{
		q--;
		ll k;
		cin>>k;
		ll ans=0;
		ll c1=0;//"D"
		ll c2=0;//"M"
		ll c3=0;//"DM"
		
		for(ll i=0;i<min(n,k);i++)
		{
			if(s[i]=='D')
			{
				c1++;
			}
			else if(s[i]=='M')
			{
				c2++;
				c3+=c1;
			}
			else if(s[i]=='C')
			{
				ans+=c3;
			}
		}

		for(ll i=k;i<n;i++)
		{
			if(s[i-k]=='D')
			{
				c1--;
				c3-=c2;
			}
			else if(s[i-k]=='M')
			{
				c2--;
			}
			
			
			
			
			if(s[i]=='D')
			{
				c1++;
			}
			else if(s[i]=='M')
			{
				c2++;
				c3+=c1;
			}
			else if(s[i]=='C')
			{
				ans+=c3;
			}
			
		}
		cout<<ans<<endl;
	}			
				
}
