#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	ll INF = 1LL<<60;
	ll n,k,q;
	cin>>n>>k>>q;
	
	vector<ll> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	auto check = [&](ll m)
	{
		vector<vector<ll> > v;
		v.push_back(vector<ll>());
		for(int i=0;i<n;i++)
		{
			if(a[i]>m)
				v[v.size()-1].push_back(a[i]);
			else
				v.push_back(vector<ll>());
		}
		ll c = 0;
		for(auto u:v)
			c+=max((ll)(u.size()-k+1),0LL);
		
		if(c<q)
			return INF;
		vector<ll> w;
		for(auto u:v)
		{
			if(u.size()<k)
				continue;
			sort(u.begin(),u.end());
			for(int j=0;j<u.size() - k+1;j++)
				w.push_back(u[j]);
		}
		sort(w.begin(),w.end());
		return w[q-1] - w[0];
	};
	
	
	ll ans = check(0);
	
	for(int i=0;i<n;i++)
		ans = min(ans,check(a[i]));
	
	cout<<ans;
	
}