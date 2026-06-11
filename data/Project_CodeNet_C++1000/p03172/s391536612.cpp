/* ****AWARE**** */
#include<bits/stdc++.h>
#include <limits.h> 
#define cut ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll          long long
#define pb          push_back
#define endl        '\n'
#define pii         pair< ll, ll>
#define vi          vector< ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(  ll i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp13       make_pair
using namespace std; 
#define MAX  3000
#define MODULO 2
using namespace std;   
#define hell 1000000007 
#define hell1 30000000000000000
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define mysizeof(i) (char*)(&i+1)-(char *)(&i);
ll T;
//double dp[MAX][MAX];
vector<ll>v;
void solve()
{    ll i,j,n,a,k;
     cin>>n>>k;
     for(i=0;i<n;i++)
      cin>>a,v.pb(a);
    ll dp[k+1]={0};// number of ways that we used i candies so far;
    dp[0]=1;
    for(i=0;i<n;i++)
    {    vector<ll>v2(k+1,0);
    	for(j=k;j>=0;j--)
    	{    
    		ll temp=dp[j];
    		ll L=j+1;
    		ll R=min(v[i],k-j)+j;
    		if(L<=R)
    		{
    			v2[L]=(v2[L]+temp)%hell;
    			if(R+1<=k)
    			{
    				v2[R+1]=(v2[R+1]-temp+hell)%hell;
    				//cout<<v2[L]<<" "<<v2[R+1]<<" //"; 
    			}
    		}
           
    	}
    	ll prefix=0;
    	for(j=0;j<=k;j++)
    	{   prefix=(prefix+v2[j])%hell;
    		dp[j]=(dp[j]+prefix)%hell;
    	}
    }
    cout<<dp[k];
}
           
int main(){ 
cut; 
ll t; 
//cin>>t;
//T=t;
 t=1;
while(t--)
solve();
return 0;
}
     
