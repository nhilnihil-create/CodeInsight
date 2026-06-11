#include<bits/stdc++.h>
using namespace std;
    
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    
#define int long long
#define double long double
    
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
    
#define ff first
#define ss second
#define mp make_pair
         
#define pb push_back
#define endl "\n" 
         
#define f(i,l,r) for(int i=l;i<=r;i++)
#define rf(i,r,l) for(int i=r;i>=l;i--)    

#define bp __builtin_popcountll
#define inf 3e15
    
const int N=2e5+5;
const int M=1e9+7;
int h,w;
char X[1001][1001];
int ans[1001][1001];
bool val(int x,int y)
{
	if(ans[x][y]!=-1) return false;
	if(x>=1 && x<=h && y>=1 && y<=w)
	return true;
	return false;
}
void solve()
{
	cin>>h>>w;
	memset(ans,-1,sizeof(ans));
	queue<pair<int,int>> q;
	f(i,1,h){
		f(j,1,w) {
		cin>>X[i][j];
		if(X[i][j]=='#')
		{
			ans[i][j]=0;
			q.push(mp(i,j));
		}
	}
	} 
	int res=0;
	while(!q.empty())
	{
		pair<int,int> p=q.front();
		q.pop();
		int x=p.ff;
		int y=p.ss;
		if(val(x+1,y)){
			q.push(mp(x+1,y));
			ans[x+1][y]=ans[x][y]+1;
			res=max(res,ans[x+1][y]);
		}
		if(val(x-1,y))
		{
			q.push(mp(x-1,y));
			ans[x-1][y]=ans[x][y]+1;
			res=max(res,ans[x-1][y]);
		}
		if(val(x,y+1))
		{
			q.push(mp(x,y+1));
			ans[x][y+1]=ans[x][y]+1;
			res=max(res,ans[x][y+1]);
		}
		if(val(x,y-1))
		{
			q.push(mp(x,y-1));
			ans[x][y-1]=ans[x][y]+1;
			res=max(res,ans[x][y-1]);
		}
	}
	cout<<res;
	
	
}
signed main()  
{
	FAST
    int t=1;
    // cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
    	// cout<<"Case #"<<tc<<": ";
    	solve();
    }
}

