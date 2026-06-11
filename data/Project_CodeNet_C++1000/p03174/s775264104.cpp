//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//Atcoder Educational DP
//N-Slimes
/*
    I ♥ CLARICE STARLING

    EXPLAINATION BELOW->
    Dp + bitmask
    
   
*/
//Iterative Solution
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define MOD7 1000000007
const ll INF=(ll)1e18+5;
int n;
int A[25][25];
void solve()
{
   int i,j;cin>>n;
   fo(i,0,n)
   fo(j,0,n)cin>>A[i][j];
   
   vector<int>dp((1<<n),0);
   dp[0]=1;//There is one way to match no pairs
   int mask;
   for(mask=0;mask<(1<<n)-1;mask++)
   {
       int num=__builtin_popcount(mask);
       for(i=0;i<n;i++)
       {
          if((A[num][i]==1)&&!(mask&(1<<i)))
          {
              dp[(mask|(1<<i))]+=dp[mask];
              dp[(mask|(1<<i))]%=MOD7;
          }
       }
   }
   cout<<dp[mask]%MOD7<<"\n";
}
int main()
{
   fastio
   solve();
  return 0;
}

