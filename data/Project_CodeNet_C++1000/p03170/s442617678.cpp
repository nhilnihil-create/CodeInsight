#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_ll.hpp>
//using boost::multiprecision::cpp_ll; // use cpp_ll as data type for large numbers 
using namespace std;

#define int ll
#define ll long long
#define pb push_back
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<long long>
#define log2(X) (63ll - __builtin_clzll(X))
#define test ll t; cin>>t; while(t--)
#define modInv(n) po(n,mod-2)%mod
#define ncr(n,r) (((fact[n]*modInv(fact[r]))%mod)*modInv(fact[n-r]))%mod

ll po(ll a, ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return res%mod;
}

signed main() 
{
    fast()
    //test
    {
      int n,k;
      cin>>n>>k;
      int arr[n+1]={0};
      int dp[k+1]={0};
      for(int i=1; i<=n; i++) cin>>arr[i];
      
      for(int i=0; i<=k; i++)
      {
          for(int j=1; j<=n; j++)
          {
              if(i>=arr[j] && dp[i-arr[j]]==0)
              {
                  dp[i]=1;
              }
          }
      }
      if(dp[k]) cout<<"First"<<"\n";
      else cout<<"Second"<<"\n";
    }   
}
