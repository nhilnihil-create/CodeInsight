/*
  Author: @yash_31
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
#define ll long long int
#define eb emplace_back
#define fatafat ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define ft first
#define sd second
#define mkpr make_pair
#define deb(x) std::cout<<#x<<":"<<x<<endl;
#define whole(x) (x).begin(),(x).end()
#define revwhole(x) (x).rbegin(),(x).rend()
#define endl "\n"
#define fbo find_by_order
#define ook order_of_key
#define init0(x) memset(x,0,sizeof(x));

using namespace std; 
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> gharKaSet;
 
const int maxlimit=2e5+2;
const ll inf=1e18;
//TTBDC

int main()
{
  fatafat
  int n,k,L,R;
  cin>>n>>k;
  int childreq;
  // for(int i=0;i<n;i++){
  //   cin>>childreq;
  //   for(int used=k;used>=0;used--){
  //     for(int ketli=1;ketli<=min(childreq,k-used);ketli++){
  //       dp[used+ketli] = (dp[used+ketli]+dp[used])%MOD;
  //     }
  //   }
  // }

  // (used+1) thi (used + min(chilreq,k-usedd)) ne add karvanu and aa bau vaar thai shake
  // so ene khali pref sum mukine pachi chhele add karvanu

  vector<ll> dp(k+1);
  dp[0]=1;
  ll prefsum=0;
  for(int i=0;i<n;i++){
    cin>>childreq;
    vector<ll> fakedp(k+1);
    for(int cused=k;cused>=0;cused--){
      L = cused + 1;
      R = cused + min(childreq,k-cused);
      if(L<=R){
        fakedp[L] = (fakedp[L] + dp[cused])%MOD;
        if(R+1<=k)fakedp[R+1] = (fakedp[R+1] - dp[cused] + MOD)%MOD;
      }
    }
    prefsum = 0;
    for(int j=0;j<=k;j++){
      prefsum = (prefsum + fakedp[j])%MOD;
      dp[j] = (dp[j] + prefsum)%MOD;
    }
  }
  cout<<dp[k];
  return 0;
}