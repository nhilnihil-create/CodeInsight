/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define pii pair<ll,ll>
# define inf (ll)1e18
# define mx2 1000005
# define mx (1<<19)
# define endl "\n"
ll a[mx];
pii F[mx];
int main()
{
	ll n;
	cin>>n;
	for(ll i=0;i<(1<<n);i++){ll x;cin>>x;F[i]={x,0};}
	for(ll i = 0;i < n; ++i) 
	{
		for(ll mask = 0; mask < (1<<n); ++mask)
		{
			if(mask & (1<<i))
			{
				vector <ll> vec={F[mask].ff,F[mask].ss,F[mask^(1<<i)].ff,F[mask^(1<<i)].ss};
				sort(vec.begin(),vec.end(),greater<ll>());
				F[mask]={vec[0],vec[1]};
			}
		}
	}	
	ll temp=0;
	for(ll i=1;i<(1<<n);i++)
	{
		temp=max(temp,(F[i].ff+F[i].ss));
		cout<<temp<<endl;
	}
}
