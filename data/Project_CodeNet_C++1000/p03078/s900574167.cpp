#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll x,y,z,k,flag=0;
	cin>>x>>y>>z>>k;
	vector<ll> a(x);
	vector<ll> b(y);
	vector<ll> c(z);
	for(int i=0;i<x;i++)
		cin>>a[i];
	for(int i=0;i<y;i++)
		cin>>b[i];
	for(int i=0;i<z;i++)
		cin>>c[i];
	sort(a.begin(),a.end(),greater<ll>());
	sort(b.begin(),b.end(),greater<ll>());
	sort(c.begin(),c.end(),greater<ll>());
	vector <ll> ans;
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		{
			for(int m=0;m<z;m++)
			{
				if((i+1)*(j+1)*(m+1)<=k)
					ans.push_back(a[i]+b[j]+c[m]);
				else
					break;
			}
		}
	}
	sort(ans.begin(),ans.end(),greater<ll>());	
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;
	return 0;
}
