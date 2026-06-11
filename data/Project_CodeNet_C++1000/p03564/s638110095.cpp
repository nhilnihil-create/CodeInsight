#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007

void solve()
{
	ll n,k;
	cin>>n>>k;
	ll c=1;
	while(n--)
	{
		if(c<=k)
			c*=2;
		else
			c+=k;
	}
	cout<<c;
    return;
}

int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}