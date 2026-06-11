/*
  Vivek Rathi
  CSE 2nd Year
  MNNIT
*/
#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 1e18
#define flush fflush(stdout);
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}
//-------------------------------Template--Above------------------------------------------------


int main()
{
	boost
	ll h,w,n;
	cin>>h>>w>>n;
	ll x,y;
	cin>>x>>y;
	string s,t;
	cin>>s>>t;
	ll curR=y,curL=y,curU=x,curD=x,maxR=y,maxL=y,maxU=x,maxD=x;
	for(ll i=0;i<n;i++)
	{
		if(s[i]=='L')
		{
			curL=curL-1;
			maxL=min(maxL,curL);
		}
		else if(s[i]=='R')
		{
			curR=curR+1;
			maxR=max(maxR,curR);
		}
		else if(s[i]=='U')
		{
			curU=curU-1;
			maxU=min(maxU,curU);
		}
		else if(s[i]=='D')
		{
			curD=curD+1;
			maxD=max(maxD,curD);
		}
		if(t[i]=='L')
		{
			curR=max(1LL,curR-1);
		}
		else if(t[i]=='R')
		{
			curL=min(w,curL+1);
		}
		else if(t[i]=='U')
		{
			curD=max(1LL,curD-1);
		}
		else if(t[i]=='D')
		{
			curU=min(h,curU+1);
		}
	}
	if(maxU<=0||maxD>h||maxL<=0||maxR>w)
	{
		cout<<"NO"<<endl;
	}
	else
		cout<<"YES"<<endl;
	return 0;
}
