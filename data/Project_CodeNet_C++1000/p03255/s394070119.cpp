#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const ull INF = ull(8e18);
ull P[222222];
ull a[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; ull x; cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		P[i]=a[i]+P[i-1];
	}
	ull res=INF;
	for(int i=1;i<=n;i++)
	{
		ull ans = 0; ull cur = 3;
		ans+=i*x;
		for(int j=n;j>=1;j-=i)
		{
			int r = j; int l = max(1, j-i+1);
			ans += (cur==3?5:cur)*(P[r]-P[l-1]);
			cur+=2;
		}
		res=min(res,ans);
	}
	res+=n*x;
	cout<<res<<'\n';
}
