
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define all(v)  v.begin(),v.end()
#define pb push_back
#define size(v)  (int) v.size()
#define fast ios_base:: sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
ll power_mod(ll a,ll x){if(x==0) return 1;ll y=power_mod(a,x/2);ll ans=(y*y)%mod; if(x%2) ans=(ans*a)%mod;return ans;}
ll inv(ll a){return power_mod(a,mod-2);}    
ll power(ll a, ll x){ if(x==0) return 1; ll y= power(a,x/2); ll ans=(y*y); if(x%2) ans*=a; return ans;}
ll dp[(1<<16)+3];
int main()
{
	 fast;
	 int n;
	 cin>>n;
	 ll a[n][n];
	 for(int i=0;i<n;i++)
	 {
	 	 for(int j=0;j<n;j++)
	 	 {
	 	 	 cin>>a[i][j];
	 	 }
	 }
	
     ll length = (1<<n);
	 ll cost[length+5]={};
     memset(dp,0,sizeof(dp));
	 for(int mask=0;mask<length;mask++)
	 {
	 	 vector<ll> bits;
         for(int i=0;i<n;i++)
         {
               if(mask&(1<<i))
               {
               	  bits.pb(i);
               }
         }

         int l = size(bits);
        
         ll here = 0;
         for(int i=0;i<l;i++)
         {
         	 for(int j = i+1;j < l;j++)
         	 {
                here = here + a[bits[i]][bits[j]];   
         	 }
         }

         dp[mask]=here;
	 }
     //for(int i=0;i<length;i++) cout<<i<<" "<<cost[i]<<endl;
     
  

  
     
     for(int mask = 1; mask < length; mask++)
     {
     	 for(int s = mask; s > 0; s = (s-1)& mask)
     	 {
     	 	 dp[mask] = max(dp[mask],dp[s^mask]+dp[s]);
     	 }
     }

     cout<<dp[length-1]<<endl;



   







}