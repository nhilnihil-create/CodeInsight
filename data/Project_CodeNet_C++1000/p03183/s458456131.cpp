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
#define N 1000
 
struct tur{
   int w,s,v;
}ar[N+5];
ll dp[N+5][N*10+5];
 
bool com(tur A,tur B){
   return A.s+A.w<B.s+B.w;
}
 
int n;
 
ll call(int idx,int taken){
   if(idx>n||taken>N*10) return 0ll;
   ll &ret=dp[idx][taken];
   if(ret!=-1) return ret;
   ll op1=0,op2=0;
   op1=call(idx+1,taken);
   if(ar[idx].s>=taken) op2=ar[idx].v+call(idx+1,taken+ar[idx].w);
   return ret=max(op1,op2);
}
 
int main ()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n;
   for(int i=1;i<=n;i++) cin>>ar[i].w>>ar[i].s>>ar[i].v;
   sort(ar+1,ar+1+n,com);
   memset(dp,-1,sizeof dp);
   cout<<call(1,0)<<"\n";
   return 0;
}
 