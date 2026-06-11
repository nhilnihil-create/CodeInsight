#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,m;
	cin >> n >> m;
	ll ans = 0;
	for(ll i = 1;i*i<=m;i++)
	{
		if(m%i==0)
		{
			if(i*n<=m&&(m-i*n)%i==0)ans = max(ans,i);
			
			if((m/i)*n<=m&&(m-(m/i)*n)%(m/i)==0)ans = max(ans,m/i);
		}
	}
	cout<<ans<<endl;
}