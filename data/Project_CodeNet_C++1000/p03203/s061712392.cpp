#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define fd find
#define in insert
#define er erase
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
const ll llinf=(1LL<<62);
const int inf=(1<<30);
const int nmax=2e5+50;
const int mod=1e9+7;
using namespace std;
int h,w,n,x,y,ans,i;
set<int>s[nmax],c[nmax];
set<int>::iterator it;
int main()
{
    //freopen("sol.in","r",stdin);
    //freopen("sol.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
   	cin>>h>>w>>n;
   	for(i=1;i<=n;i++)
   	{
   		cin>>x>>y;
   		c[y].in(x);
   		s[x].in(y);
	}
	x=1,ans=h;
	for(i=1;i<=h;i++)
	{
		if(s[i].fd(x)==s[i].end())
		{
			it=c[x].lower_bound(i);
			if(it!=c[x].end())
			{
				ans=min(ans,(*it)-1);
			}
			x++;
		}
	}
	cout<<ans<<endl;
    return 0;
}