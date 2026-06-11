#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

using namespace std;

typedef long long ll;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pb_ds;

#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
#define pi pair<int,int>
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define mod 1000000007
#define pai acos(-1)
#define N 100005

int ar[N][3],dp[N][3];

int main ()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;cin>>n;
   for(int i=1;i<=n;i++) cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
   for(int i=n;i>=1;i--){
      dp[i][0]=max(dp[i+1][1],dp[i+1][2])+ar[i][0];
      dp[i][1]=max(dp[i+1][0],dp[i+1][2])+ar[i][1];
      dp[i][2]=max(dp[i+1][0],dp[i+1][1])+ar[i][2];
   }
   cout<<max(dp[1][0],max(dp[1][1],dp[1][2]))<<"\n";
   return 0;
}
