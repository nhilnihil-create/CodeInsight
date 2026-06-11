 
#include<bits/stdc++.h>

#define ll long long int
#define f(i,n) for(ll i = 0; i < n ; i++)
#define fn(i,n) for(ll i = 1; i <= n ; i++)
#define F first 
#define pb push_back
#define S second
using namespace std;
ll dp[3005][3005];
char a[1001][1001];
ll r = 0, c = 0;
ll mn = INT_MAX;
ll mx = 1000000007;

ll numberOfPaths(ll n, ll m) 
{ 
    if(a[n-1][m-1] == '#')
    return dp[n][m] = 0;
  
    if (m == 1 || n == 1){

      if(n == 1)
      {
        ll i = m-1;
        while(i)
        {
          if(a[0][i] == '#')
            return dp[n][m] = 0;
            i--;
        }
      }
        if(m == 1)
        {
        ll i = n-1;
        while(i)
        {
          if(a[i][0] == '#')
            return dp[n][m] = 0;
            i--;
        } }    
      return 1;
    }
         

    if(dp[n][m] != -1)
      return (dp[n][m])%mx;
    
     
    return dp[n][m] = (numberOfPaths(n - 1, m)%mx + numberOfPaths(n, m - 1)%mx)%mx; 
    
} 


 
int main()
{

     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
     
         ll n,m;
         memset(dp,-1,sizeof(dp));
         cin>>n>>m;

         f(i,n)
         for(ll j = 0; j < m; j++)
            cin>>a[i][j];
           
          
         

         //ll p[n],w[n];
        
         //string s1,s2; cin>>s1>>s2;
         //ll n = s1.length();
         //ll m = s2.length();
         //f(i,10) dp[i] = 100;
         //memset(dp,-1,sizeof(dp));
         //sol(s1,s2,n,m);
         
         cout<<numberOfPaths(n,m);
         
         //cout<<dp[0][3]<<endl;
         
        
         
   return 0;
}
