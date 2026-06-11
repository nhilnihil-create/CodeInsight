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
	int a[n];
	for(int i = 0; i<n; i++) cin>>a[i];
	vector<ar<int,2> > v;
	int x = *min_element(a,a+n);
	if(x<=0)
	{
		int f = *max_element(a,a+n);
		if(f>=0)
		{
			if(abs(x)<f)
			{
				int j = -1;
				for(int i= 0; i<n;i++)
				{
					if(a[i]==f)
						j = i;
				}
				for(int i = 0; i<n;i++)
				{
					if(i==j) continue;
					a[i] += a[j];
					v.pb({j+1,i+1});
				}
				for(int i = 1;i<n; i++)
				{
					a[i] += a[i-1];
					v.pb({i,i+1});
				}
			}
			else
			{
				int j = -1;
				for(int i= 0; i<n;i++)
				{
					if(a[i]==x)
						j = i;
				}
				for(int i = 0; i<n;i++)
				{
					if(i==j) continue;
					a[i] += a[j];
					v.pb({j+1,i+1});
				}
				for(int i = n-2;i>=0; i--)
				{
					a[i] += a[i+1];
					v.pb({i+2,i+1});
				}
			}
		}
		else
		{
			for(int i = n-2; i>=0; i--)
			{
				a[i] += a[i+1];
				v.pb({i+2,i+1});
			}
		}
	}
	else
	{
		for(int i = 1; i<n; i++)
		{
			a[i] += a[i-1];
			v.pb({i,i+1});
		}
	}
	cout<<v.size()<<endl;
	for(auto it:v)
		cout<<it[0]<<" "<<it[1]<<endl;
	return 0;
}