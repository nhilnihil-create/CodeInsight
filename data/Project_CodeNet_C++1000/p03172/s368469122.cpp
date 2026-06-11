//Author:- S_Aditya

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN
const ll mod=1e9+7;         
const int N=1e5+4;

//dp[i][j] tells the no. of ways to distribute total of j candies among the first i boys
//according to the given constraints.

ll dp[104][N];

int main()                  
{
    int n,k;
    
    scn(n); scn(k);
    
    int a[n];
    
    rep(i,0,n)
    scn(a[i]);
    
    dp[0][0]=1;
    
    rep(i,0,n)
    {
      	if(i)
        rep(j,1,k+1)
        dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        
        rep(used,0,k+1)
        {
            int l=used,r=used+min(k-used,a[i]);
            
            dp[i+1][l]=(dp[i+1][l]+dp[i][used])%mod;
            
            dp[i+1][r+1]=(dp[i+1][r+1]-dp[i][used]+mod)%mod;
        }
    }
  	
  	rep(j,1,k+1)
    dp[n][j]=(dp[n][j]+dp[n][j-1])%mod;
        
    
    cout<<dp[n][k];
} 
