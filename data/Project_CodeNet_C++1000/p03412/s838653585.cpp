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
const int M = 2e5+5;
int a[M],b[M];
int getRes(int x,int n)
{
	vector<int> v;
	for(int i=1;i<=n;i++)
		v.pb(b[i]%(2*x));
	sort(all(v));
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		int y = a[i];
		y = y%(2*x);
		int p = (int)(lower_bound(all(v),x-y)-v.begin());
		int q = (int)(lower_bound(all(v),2*x-y)-v.begin());
		int r = (int)(lower_bound(all(v),3*x-y)-v.begin());
		p = n-p,q=n-q,r=n-r;
		cnt = (cnt+p+r-q)%2;
	}
	if(cnt)
		return x;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int ans = 0;
	for(int i=0;i<=28;i++)
	{
		ans += getRes((1<<i), n);
	}
	cout<<ans<<"\n";
	return 0;
}