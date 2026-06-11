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
const int M=2002;
int a[M];
bool solve(int x,int sm,int k,int q,int n)
{
	vector<int> cur;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<sm)
		{
			sort(all(cur));
			for(int j=0;j<=sz(cur)-k;j++)
			{
				if(cur[j]<=x)
					tot++;
			}
			cur.clear();
		}
		else
		{
			cur.pb(a[i]);
		}
	}
	sort(all(cur));
	for(int i=0;i<=sz(cur)-k;i++)
	{
		if(cur[i]<=x)
			tot++;
	}
	// if(x==1 && sm==1)
	// {
	// 	cout<<tot<<endl;
	// }
	if(tot>=q)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k,q;
	cin>>n>>k>>q;
	vector<int> v;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v.pb(a[i]);
	}
	sort(all(v));
	int res=1e9;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=sz(v)-1,p=-1;
		r=0;
		while(r<sz(v) && v[r]!=a[i])
			r++;
		while(l<r)
		{
			int m=(l+r)/2;
			if(m==p)
				m++;
			p=m;
			if(solve(a[i],v[p],k,q,n))
			{
				l=m;
			}
			else
			{
				r=m-1;
			}
		}
		if(solve(a[i],v[l],k,q,n))
		{
			res=min(res,a[i]-v[l]);
		}
	}
	cout<<res<<"\n";
	return 0;
}