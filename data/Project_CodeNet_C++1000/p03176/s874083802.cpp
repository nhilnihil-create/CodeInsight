#include<bits/stdc++.h>
#define int long long int  //comment for large arrays
#define pll pair<int,int>
#define dbl long double
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define eps 0.00000001
#define INF 10000000000000001
#define all(x) (x).begin(),(x).end()
#define LB(v,x) (lower_bound(all(v),x) - v.begin()) 
#define UB(v,x) (upper_bound(all(v),x) - v.begin())
#define size(x) (int)(x).size()
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define popb() pop_back()
#define popf() pop_front()
#define mp(x,y) make_pair((x),(y))
#define vec(dt) vector<dt>
#define vv(dt) vector<vector<dt>>
#define fastio(x) ios_base::sync_with_stdio(x); cin.tie(NULL)
#define init(v,s) memset(v,s,sizeof(v)) 
#define bug(x) cerr<<"LINE: "<<__LINE__<<" || click to see test details "<<#x<<" = "<<x<<endl
#define loop(i,s,n) for(int i=s;i<n;i++)
#define print(v) for(auto it:v) cout<<it<<" "; cout<<endl 
using namespace std;


int n,seg_tree[4*200001+1]; // using 1 based indexing

void build(int node,int tl,int tr,int dp[])
{
	if(tl==tr) seg_tree[node] = dp[tl];
	else
	{
		int tm = (tl + tr)>>1;
		build(2*node,tl,tm,dp);
		build(2*node + 1,tm+1,tr,dp);
		seg_tree[node] = max(seg_tree[2*node], seg_tree[2*node + 1]);
	}	
}

void update(int node,int tl,int tr,int pos,int value)
{
	if(tl==tr) seg_tree[node] = value;
	else 
	{
		int tm = (tl + tr)>>1;
		if(pos <= tm) update(2*node,tl,tm,pos,value);
		else update(2*node + 1,tm+1,tr,pos,value);
		seg_tree[node] = max(seg_tree[2*node], seg_tree[2*node + 1]);
	}
}

int query(int node,int tl,int tr,int l,int r)
{
	if(l>r) return 0;
	if(tl==l && tr==r) return seg_tree[node];
	int tm = (tl + tr)>>1;
	return max(query(2*node,tl,tm,l,min(r,tm)), query(2*node + 1,tm+1,tr,max(l,tm+1),r));
}



signed main()
{
	fastio(0);
	cin>>n;
	int h[n+1],a[n+1],dp[n+1];
	loop(i,1,n+1) cin>>h[i];
	loop(i,1,n+1) cin>>a[i];
	init(dp,0);
	build(1,1,n,dp);
	loop(i,1,n+1)
	{
		dp[h[i]] = query(1,1,n,1,h[i]-1) + a[i];
		update(1,1,n,h[i],dp[h[i]]);
	}
	cout<<seg_tree[1]<<endl;
	return 0;		
}