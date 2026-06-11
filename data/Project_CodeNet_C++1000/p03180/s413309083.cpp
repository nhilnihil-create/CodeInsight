#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long 
#define pb push_back
#define fo(i,N) for(int i = 0 ; i < N ; i++)
#define foo(i,x,N) for (int i = x; i < N ; i++)
#define fill(a,val) memset(a,val,sizeof(a))
#define fastio()  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define ff first
#define ss second
#define MAX 1234567
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define inf 1e14+1
#define all(a) a.begin(),a.end()
int n;
int  arr[17][17];
ll dp[1ll<<16];
ll sum[1ll<<16];


ll calc(int idx)
{
  ll ans = 0;

  fo(i,17)
  { if ( (idx & (1<<i)) == 0)
    continue;
    for(int j = i+1; j < 17 ; j++)
     {
          if ( idx & (1<<j))
            ans += arr[i][j];
     }
  }
  return ans;
}

void pre()
{
   foo(i,1,1<<n)
   {
    dp[i] = inf;
    sum[i] = calc(i);
   }
}

ll solve(int i)
{ 
   if ( i == 0)
    return 0;

    if ( dp[i] != inf)
      return dp[i];
    
    ll ans = 0;
    for(int m = i ; m != 0 ; m = (m-1)&i)
    {
      ans = max(ans,sum[m]+solve(i^m));

    }
    return dp[i] = ans;
}


int main()
{ 
  cin >> n;
  fo(i,n)
  {
    fo(j,n)
    cin >> arr[i][j];
  }
  pre();



  cout << solve((1<<n)-1) << endl;


 

}