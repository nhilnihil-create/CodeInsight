#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 10000000000007;

int main()
{
	ll a,b,q;
	cin >> a >> b >> q;
	vector<ll> s(a),t(b),x(q);
	rep(i,a)
	{
		cin >> s[i];
	}
	rep(i,b)
	{
		cin >> t[i];
	}
	rep(i,q)
	{
		cin >> x[i];
	}
	rep(i,q)
	{
		auto sbin =lower_bound(ALL(s),x[i]);
		auto tbin = lower_bound(ALL(t),x[i]);

		ll fs = abs(x[i]-*sbin);
		ll ft = abs(x[i]-*tbin);
		ll bs = abs(x[i]-max(*s.begin(),*(sbin-1)));
		ll bt = abs(x[i]-max(*t.begin(),*(tbin-1)));
		
		ll A = max(fs,ft);
		ll B = max(bs,bt);
		if(sbin==s.begin())B=INF;
		if(tbin==t.begin())B=INF;
		if(sbin==s.end())A=INF;
		if(tbin==t.end())A=INF;
		ll C = min(fs,bs)+min(ft,bt)+min(min(fs,bs),min(ft,bt));
		
		//cout<<A<<';'<<B<<';'<<C<<endl;
		cout<<min(A,min(B,C))<<endl;
	}

	return 0;
}