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

ll dp[401][401];
ll pref[401];

ll solve(int L,int R){
  if(dp[L][R]!=-1)return dp[L][R];
  else if(L==R)return dp[L][R] = 0;
  ll res = inf,cres;
  for(int i=0;i<R-L;i++){
    cres = solve(L,L+i) + solve(L+i+1,R) + pref[R];
    cres -= (L-1<0 ? 0 : pref[L-1]);
    res = min(res,cres);
  }
  return dp[L][R] = res;
}

int main()
{
  fatafat
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
    if(i==0)pref[i]=v[i];
    else pref[i]=pref[i-1]+v[i];
  }
  for(int i=0;i<n;i++){for(int j=0;j<n;j++){dp[i][j]=-1;}}
  cout<<solve(0,n-1);
  return 0;
}