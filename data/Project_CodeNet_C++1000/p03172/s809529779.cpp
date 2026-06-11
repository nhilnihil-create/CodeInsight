#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
#define rep(i,a,n) for(int i=a ; i<n ; i++)
#define pb push_back

ll p=1e9+7 ;

int main()
{
	ll n,k ;
	cin>>n>>k ;
	ll lim ;
	ll dp[k+1] ;
	ll fake[k+1] ;
	
	memset(dp,0,sizeof(dp)) ;
	dp[0]=1 ;
	rep(i,0,n)
	{
		memset(fake,0,sizeof(fake)) ;
		cin>>lim ;
		for(ll used=k ; used>=0 ; used--)
		{
			int l=used+1 , r=used+min(lim,k-used) ;
			if(l<=r)
			{
				fake[l] = (fake[l] + dp[used])%p ;
				if(r+1<=k)
					fake[r+1] = ((fake[r+1] - dp[used]) + p ) %p  ;
 			}
		}
		ll pref=0 ;
		rep(i,0,k+1)
		{
			pref = (pref+fake[i])%p ;
			dp[i] = (dp[i]+pref)%p ;
		}
	}
	
	cout<<dp[k]<<endl ;

	return 0;
}