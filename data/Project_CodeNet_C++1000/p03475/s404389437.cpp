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
	int c[n-1],s[n-1],f[n-1];
	for(int i = 1; i<n; i++)
		cin>>c[i-1]>>s[i-1]>>f[i-1];
	int ans = 0,time = 0;
	vector<int> v;
	for(int j = 0; j<n-1; j++)
	{
		time = 0;
		for(int i = j; i<n-1; i++)
		if(time<=s[i])
		{
			time += ((s[i]-time)+c[i]);
		}
		else
		{
			int h = s[i];
			while(h<time)
				h += f[i];
			time += (h-time)+c[i];
		}
		v.pb(time);
	}
	for(auto it: v) cout<<it<<endl;
		cout<<0<<endl;
	return 0;
}