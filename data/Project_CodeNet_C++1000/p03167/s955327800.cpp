 
#include<bits/stdc++.h>

#define ll long long int
#define f(i,n) for(ll i = 0; i < n ; i++)
#define fn(i,n) for(ll i = 1; i < n ; i++)
#define F first 
#define pb push_back
#define S second
using namespace std;
ll dp[3005][3005];
char a[1001][1001];
ll r = 10000000, c = 10000000;
ll mn = INT_MAX;
ll mx = 1000000007;

ll numberOfPaths(ll n, ll m) 
{ 
    f(i,n)
    dp[i][0] = 1;

    for(ll j = 0; j < m; j++)
      dp[0][j] = 1;

     f(i,n)
         for(ll j = 0; j < m; j++)
          if(a[i][j] == '#')
            dp[i][j] = 0;


    fn(i,n)
         for(ll j = 1; j < m; j++)
            {
              if(dp[i][j] == 0)
                continue;

                dp[i][j] = (dp[i-1][j]%mx + dp[i][j-1]%mx)%mx;
            }
    
     
    return dp[n-1][m-1] ;//= (numberOfPaths(n - 1, m)%mx + numberOfPaths(n, m - 1)%mx)%mx; 
    
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
         for(ll j = 0; j < m; j++){
            cin>>a[i][j];
            if(i == 0 &&a[i][j] == '#' && r == 10000000)
              r = j;
            if(j == 0 && a[i][j] == '#' && c == 10000000)
              c = i;
            
         }

         while(r < m){
              a[0][r] = '#'; r++;}
          while(c < n){
              a[c][0] = '#'; c++;}
           
         
         

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
