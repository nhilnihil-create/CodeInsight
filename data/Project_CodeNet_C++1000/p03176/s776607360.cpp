#include<bits/stdc++.h>
using namespace std;
#define   FASTIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   vi vector<long long>
#define   vvi vector<vector<long long>>
#define   all(a) (a).begin(), (a).end()
#define   rep(i,a,b)  for(int  i=a;i<b;i++)
#define   tr(it, a)   for(auto it=a.begin();it!=a.end();it++)
#define   pb push_back
#define   endl "\n"
#define   dbg(x,y) cout<<(x)<<" -->  "<<(y)<<endl
#define   dbg2(k)   cout<<(k)<<" * "<<endl;
#define   F first
#define   S second
#define   int long long
#define   ll long long

const int  inf=1e6+2;
const int  ninf=-1e9 ;
const int  mod=1e9+7;
int cost[200005],h[200005];
int BIT[200005];
int n;
void update(int idx,int val)
{
	while(idx<n)
	{
	   BIT[idx]=max(BIT[idx],val);
	   idx+=((idx)&(-idx));
	}
}

int fun(int idx)
{
	int ans=0;
	
	while(idx>0)
	{
	  ans=max(ans,BIT[idx]);
	  idx-=(idx&(-idx));	
	}
	return ans;
}


void solve()
{
  	int m,i,j,x,d,bt,y,p,g,k,low,high,res,mid,q;
  	cin>>n;
  	for(i=0;i<n;i++)
  	{
  		cin>>h[i];
	}
	for(i=0;i<n;i++)
  	{
  		cin>>cost[i];
	}
	int ans=0;
	for(i=0;i<n;i++)
  	{
  	  mid=fun(h[i]-1);
  	  res=mid+cost[i];
//  	  cout<<i<<" "<<mid<<" "<<res<<" "<<h[i]<<endl;
  	  ans=max(ans,res);
  	  update(h[i],res);
  	}
	   
	cout<<ans<<endl;	
}
signed main()
{
//   FASTIO;
   int T;
   T=1;
//   cin>>T;
   while(T--)
   {
    solve();
   }
   return 0;
}
