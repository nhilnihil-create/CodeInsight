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
ll dp[MAX][MAX];
vector<ll>v;
void solve()
{    ll i,j,n,a,k,mn,cnt=1,ans,sum=0,l,r;
     cin>>n;
     for(i=0;i<n;i++)
     	cin>>a,v.pb(a);

     for(l=n-1;l>=0;l--)
     {

     	for(r=l;r<n;r++)
     	{
            
            if(l==r)
            {
            	dp[l][r]=0;
            	continue;
            }
            dp[l][r]=1e13;
            sum=0;
            for(i=l;i<=r;i++)
            	sum+=v[i];
            for(i=l;i<=r;i++)
            {
            	 dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+sum);
            }
     	}
     }
   cout<<dp[0][n-1];
      
    
    
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
     
