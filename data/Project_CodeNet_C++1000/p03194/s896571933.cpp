/* ****TCIITB**** */

#include<bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

// #define N  100005
ll n,p;
ll ans;

  

int main()
{
	
	io

	
	cin>>n>>p;
	if(n==1 || p==1)
	{
		cout<<p<<endl;
		exit(0);
	}
	std::map<ll,ll> c;
	rep(i,1,sqrt(p)+1)
	{
		if(!(p%i))
		{
			c[i]++;
			if((p/i)!=i)
			{
				c[p/i]++;
			}
		}

	}
	for(auto i:c)
	{
		ll z=i.F;
		ll cnt=0;
		ll zz=p;
		if(z==1)
			continue;
		while(zz>1)
		{
			if(!(zz%z))
			{
				zz/=z;

				cnt++;
			}
			else
				break;
		}
		if(cnt>=n)
			ans=z;
	}
	cout<<max(1ll,ans);

}