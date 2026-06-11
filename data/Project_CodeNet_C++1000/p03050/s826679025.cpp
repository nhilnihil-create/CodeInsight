#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt" , "r" , stdin);
	// freopen("output.txt" , "w" , stdout);
	// #endif

	ll n,ans=0;
	cin>>n;
	vector<ll>v;
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ll a=i-1,b=n/i-1;
			if(n/i==i)
			{
				if(a)
				{
					if(n/a==n%a)
						ans+=a;
				}
			}
			else
			{
				if(a)
				{
					if(n/a==n%a)
						ans+=a;
				}
				if(b)
				{
					if(n/b==n%b)
						ans+=b;
				}
			}

		}
	}
	cout<<ans<<endl;
	
}
