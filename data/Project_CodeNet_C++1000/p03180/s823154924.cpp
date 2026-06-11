/*
    STARK_BOY
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i<=b;i++)
#define bac(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef vector< ll > vi;
typedef vector<pair<ll,ll> > vpii;
typedef pair<ll,ll> pii;
#define all(c) c.begin(),c.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setbitc(x) __builtin_popcount(x)
#define init(x,a) memset(x,a,sizeof(x))
#define PI           3.14159265358979323846  /* pi */
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
#define N 16
//Variables Start
ll inf=1e18,MOD=1e9+7;
ll n,m,k,ar[N][N],dp[1<<N];
string s,s1;
//Variables End

int main()
{
    ios
    int ti=1;
    //cin>>ti;
    while(ti--)
    {
		cin>>n;  
		rep(i,0,n)rep(j,0,n)cin>>ar[i][j];

		rep(mask,1,1<<n)
		{
			vi active;
			rep(pos,0,n)if(mask&(1<<pos))active.pb(pos);
			//for(auto i:active)cout<<i<<" ";
			//	cout<<endl;
			rep(i,0,active.size())rep(j,i,active.size())
			dp[mask]+=ar[active[i]][active[j]];

			for(int sub=mask;sub>0;sub=(sub-1)&mask)
			{
				dp[mask]=max(dp[mask],dp[sub]+dp[sub^mask]);
			}
			//cout<<dp[mask]<<endl;
		}

		cout<<dp[(1<<n)-1]<<endl;

    }
    return 0;
        
}