#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int clamp(ll a, ll low, ll high)
{
	if(a<low)return low;
	else if(a>high)return high;
	else return a;
}

int main()
{
	int a,b,q;cin>>a>>b>>q;
	vector<ll> s(a);
	vector<ll> t(b);
	vector<ll> x(q);
	int i;
	rep(i,a)cin>>s[i];
	rep(i,b)cin>>t[i];
	rep(i,q)cin>>x[i];
	rep(i,q)
	{
		ll ans=123456789012;
		int inds=lower_bound(all(s),x[i])-s.begin();
		int indt=lower_bound(all(t),x[i])-t.begin();
		int j,k;
		rep(j,2)rep(k,2)
		{
			int is=clamp(inds-j,0,a-1);
			int it=clamp(indt-k,0,b-1);
			ll kans=0;
			if(x[i]>max(s[is],t[it])||x[i]<min(s[is],t[it]))
			{
				kans+=max(abs(x[i]-s[is]),abs(x[i]-t[it]));
			}
			else
			{
				kans+=max(abs(x[i]-s[is]),abs(x[i]-t[it]));
				kans+=min(abs(x[i]-s[is]),abs(x[i]-t[it]))*2;
			}
			ans=min(ans,kans);
		}
		cout<<ans<<endl;
	}
}
