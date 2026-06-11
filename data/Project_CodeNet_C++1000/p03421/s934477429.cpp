#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
using ll=long long;
ll n,a,b;
int main()
{
	cin>>n>>a>>b;
	if (n<=a+b-2 || n>a*b)
	{
		cout<<-1<<endl;
		return 0;
	}
	vector <ll> res;
	for (ll i=b-1;i>=0;--i) res.push_back(i);
	if (a!=1)
	{
		ll rem=n-b,p=rem/(a-1),r=rem%(a-1);
		ll b=r,c=a-1-r;
		for (int i=0;i<b;++i)
		{
			int t=sz(res);
			for (int j=0;j<p+1;++j)
			{
				res.push_back(t+p-j);
			}
		}
		for (int i=0;i<c;++i)
		{
			int t=sz(res);
			for (int j=0;j<p;++j)
			{
				res.push_back(t+p-1-j);
			}
		}
	}
	for (int i=0;i<sz(res);++i)
	{
		cout<<res[i]+1;
		if (i!=sz(res)-1) cout<<" ";
	}
	cout<<endl;
	return 0;
}