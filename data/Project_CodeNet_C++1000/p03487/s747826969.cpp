#define _USE_MATH_DEFINES //M_PI, M_E
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	map<int,int> m;
	for(int i = 0,j; i<n; i++)
	{
		cin>>j;
		m[j]++;
	}
	int ans = 0;
	for(auto i:m)
	{
		if(m[i.first]>i.first)
			ans += m[i.first]-i.first;
		else if(m[i.first]<i.first)
			ans += m[i.first];
	}
	cout<<ans<<endl;
	return 0;
}