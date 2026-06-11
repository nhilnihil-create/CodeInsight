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
	int n,k;
	cin>>n>>k;
	int a[int(2e5)+1]={0};
	set<int> s;
	for(int i = 0,j; i<n; i++)
	{
		cin>>j;
		a[j]++;
		s.insert(j);
	}
	int ans = 0;
	if(s.size()>k)
	{
		set<ar<int,2> > g;
		for(int i = 1; i<200001; i++)
			if(a[i])
				g.insert({a[i],i});
		while(g.size()>k)
		{
			auto y = *g.begin();
			g.erase(y);
			ans += y[0];
		}
	}
	cout<<ans<<endl;
	return 0;
}