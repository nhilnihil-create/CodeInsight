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
#define vpi vector<pair<int,int> >
#define vpl vector<pair<ll,ll> >
#define mkpr make_pair
#define todec() to_ulong()
#define toldec() to_ullong()
#define deb(x) std::cout<<#x<<":"<<x<<endl;
#define whole(x) (x).begin(),(x).end()
#define revwhole(x) (x).rbegin(),(x).rend()
#define endl "\n"
#define fbo find_by_order
#define ook order_of_key
 
using namespace std; 
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> gharKaSet;
 
const int maxlimit=5e5+2;
const ll inf=1e12;
 
ll dp[(1<<21)+1][22];
int n;
ll allset;
 
vector<int> cpht[21];
//can person have this topic
 
ll getAns(int mask,int tillass){
  // all got topics
  if(mask==allset)return 1;
  //topics finished
  if(tillass==21)return 0;
  if(dp[mask][tillass]!=-1)return dp[mask][tillass];
  ll ans=0;
  for(auto &st :cpht[tillass]){
    if((mask & (1<<st))==0){
      ans= (ans+getAns(mask | (1<<st),tillass+1))%MOD;
    }
  }
  dp[mask][tillass] = ans;
  return ans;
}
 
int main()
{
  fatafat
  bool interested;
  cin>>n;
  allset=(1LL<<n)-1;
  for(int i=0;i<21;i++)cpht[i].clear();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>interested;
      if(interested)cpht[j].eb(i);
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<getAns(0,0)<<endl;
  return 0;
} 
