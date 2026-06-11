 
#include<bits/stdc++.h>

#define ll long long int
#define f(i,n) for(ll i = 0; i < n ; i++)
#define fn(i,n) for(ll i = 1; i <= n ; i++)
#define F first 
#define pb push_back
#define S second
using namespace std;
ll dp[3005][3005];

ll mn = INT_MAX;
void sol(string s1, string s2, ll n , ll m)
{
    
   ll dp[n+1][m+1] = {};
    
    fn(i,n)
    {
      for(ll j = 1 ; j <= m ; j++)
      {
        if(s1[i-1] == s2[j-1])
         dp[i][j] = 1 + dp[i-1][j-1];

        else
         dp[i][j] = max(dp[i-1][j],  dp[i][j-1]);
      }
    }
    //cout<<dp[n][m]<<endl;
string s;
       ll i = n, j = m;
       while(i > 0 && j > 0)
         {
            if(s1[i-1] == s2[j-1])
            {
              s.pb(s1[i-1]);
              i--;j--;
            }
            else
            {
              if(dp[i][j-1] > dp[i-1][j])
                j--;
              else
                i--;

            }
         } 
         reverse(s.begin(),s.end());
         cout<<s;
}


 
int main()
{

     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
     
         //ll n;
          memset(dp,-1,sizeof(dp));
         //cin>>n>>W;
         //ll p[n],w[n];
        
         string s1,s2; cin>>s1>>s2;
         ll n = s1.length();
         ll m = s2.length();
         //f(i,10) dp[i] = 100;
         //memset(dp,-1,sizeof(dp));
         sol(s1,s2,n,m);
         
         
         
         //cout<<dp[0][3]<<endl;
         
        
         
   return 0;
}
