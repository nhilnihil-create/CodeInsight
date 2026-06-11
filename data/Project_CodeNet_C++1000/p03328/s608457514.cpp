#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,ll>::iterator itll;
typedef long double ld;
typedef map<ll,ll> mapll;

#define con continue
#define pb push_back
#define fi first
#define se second
#define fr front()
#define INF 1000000000000000000
#define all(vl) vl.begin(),vl.end()
#define m_p make_pair 
#define sz(a) sizeof(a)
#define forn(mp,it) for(it = mp.begin();it!=mp.end();it++)
#define FOR(i,a,n) for(int i=a;i<n;i++) 
#define FORE(i,a,n) FOR(i,a,n+1)
#define Endl endl
#define eNdl endl
#define enDl endl
#define endL endl

int main()
{
	map<ll,ll> mp;
	FOR(i,1,1000)
	{
		mp[i*(i+1)/2] = i;
	}
	ll a,b;
	cin>>a>>b;
	ll ans = 1;
	for(ans = 1;ans<=499500;ans++)
	{
		ll t1 = a+ans;
		ll t2 = b+ans;
		if(mp[t1]&&mp[t2]&&mp[t2]-mp[t1] == 1)
		{
			cout<<ans<<Endl;
			return 0;
		}
	}
	return 0;
} 
