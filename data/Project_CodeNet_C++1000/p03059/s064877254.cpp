#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll a,b,t,ti,sum=0;
	cin>>a>>b>>t;
	t++;
	ti=a;
	while(ti<t)
		sum+=b,ti+=a;
	cout<<sum;
	return 0;
}
