
// Problem : 
// 			Q - Flowers
// 			Editorial
// 		
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_q
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define db double
#define mod 1000000007
#define pb push_back
#define pp pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repe(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=b;i>=a;i--)
#define maxn 200005
#define ss second
#define ff first
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
int inv(int a, int b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
int st[5*maxn],n,a[maxn];
vector<pair<int,int> > v;
int query(int p,int l,int r,int j)
{
	if(l > j)
		return 0;
	if(r <= j)
		return st[p];
	int m=(l+r)/2;
	return max(query(2*p,l,m,j),query(2*p+1,m+1,r,j));
}
void update(int p, int l,int r,int j,int val)
{
	if(l > j || r < j)
		return;
	if(l == r)
	{
		st[p]=val;
		return;
	}
	int m=(l+r)/2;
	update(2*p,l,m,j,val);
	update(2*p+1,m+1,r,j,val);
	st[p]=max(st[2*p],st[2*p+1]);
}
void solve()
{
	cin >> n;
	rep(i,0,n)
	{
		int x;
		cin >> x;
		v.pb({x,i});
	}
	sort(all(v));
	rep(i,0,n)
		cin >> a[i];
	for(auto &x:v)
	{
		int tmp = query(1,0,n-1,x.ss);
		update(1,0,n-1,x.ss,tmp+a[x.ss]);
	}
	cout << st[1];
}
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while(t--)
    solve();
    return 0;
}
