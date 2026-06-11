#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const int M=2e5+5;
ll a[M],cs[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cs[i]=cs[i-1]+a[i];
	}
	int l=1,r=1;
	ll ans=1e16;
	for(int i=2;i<=n-2;i++)
	{
		while(1)
		{
			if(l==i-1)
				break;
			if(abs((ll)2*cs[l]-cs[i])>abs((ll)2*cs[l+1]-cs[i]))
				l++;
			else
				break;
		}
		r=max(r,i+1);
		while(1)
		{
			if(r==n-1)
				break;
			if(abs((ll)2*cs[r]-cs[i]-cs[n])>abs((ll)2*cs[r+1]-cs[i]-cs[n]))
				r++;
			else
				break;
		}
		std::vector<ll> vt;
		vt.pb(cs[l]);vt.pb(cs[i]-cs[l]);vt.pb(cs[r]-cs[i]);vt.pb(cs[n]-cs[r]);
		sort(all(vt));
		ans=min(ans,vt[3]-vt[0]);
	}
	cout<<ans<<"\n";
	return 0;
}