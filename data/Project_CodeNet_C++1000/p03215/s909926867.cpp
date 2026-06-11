#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
const int mod = 1e9+7;
const int mx = INT_MAX;
const long double pi = 4*atan((long double)1);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define file "orz"
ll pref[1005];
vector<ll> v;
int main()
{
	//freopen(file".inp","r",stdin);
	//freopen(file".out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>pref[i];
		pref[i] += pref[i-1];
	}
	for(ll i=0;i<=n;i++)
		for(ll j=i+1;j<=n;j++)
			v.eb(pref[j]-pref[i]);
	ll ans = 0;
	for(ll i=40;i>=0;i--)
	{
//		cout<<ans<<endl; 
		ll c = 0;
		for(auto j:v)
		{
			ll x = ans&j;
			if(x == ans)
			{
				if(j & (1LL<<i))
					c++;
			}
		}
		if(c>=k)
		{
//			cout<<c<<" "<<k<<endl;
//			cout<<c<<" "<<k<<endl;		 
			ans = ans^(1LL<<i);
		}	
	}
	cout<<ans;
}
