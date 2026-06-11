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

// dekh k kiya

double dp[301][301][301];
int n;

double solve(int x,int y,int z){
  if(dp[x][y][z]!=-1)return dp[x][y][z];
  if(x+y+z==0)return dp[x][y][z]=0;
  double xyz = x+y+z;
  double N = n;
  dp[x][y][z]=(N-xyz)/xyz;
  if(x!=0)dp[x][y][z]+=x*(solve(x-1,y,z)+1)/xyz;
  if(y!=0)dp[x][y][z]+=y*(solve(x+1,y-1,z)+1)/xyz;
  if(z!=0)dp[x][y][z]+=z*(solve(x,y+1,z-1)+1)/xyz;
  return dp[x][y][z];
}

int main()
{
  fatafat
  int x;
  cin>>n;
  int cnts[4]={0,0,0,0};
  for(int i=0;i<n;i++){cin>>x;cnts[x]++;}
  for(int i=0;i<=300;i++){
    for(int j=0;j<=300;j++){
      for(int k=0;k<=300;k++){
        dp[i][j][k]=-1;
      }
    }
  }
  cout<<fixed<<setprecision(10)<<solve(cnts[1],cnts[2],cnts[3]);
  return 0;
}