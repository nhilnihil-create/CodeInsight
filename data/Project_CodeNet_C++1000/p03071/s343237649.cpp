#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll a,b;
	cin>>a>>b;
	ll ans=0;
	if(a>b)
		ans=a,a--;
	else
		ans=b,b--;
	if(a>b)
		ans+=a;
	else
		ans+=b;
	cout<<ans;
	return 0;
}
