#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;
typedef pair<ll,pii> ipii;
#define MOD 1000000007
#define mod(a) ((a)%MOD)
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define dbg(x) cerr<<#x<<" = "<<x<<"\n"
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<"\n"
#define dbg3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<"\n"
#define INF (1LL<<60)
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(),v.end()
#define endl '\n'
ll gcd(ll a,ll b){if(a==0) return b; return gcd(b%a,a);}
ll powm(ll base,ll exp,ll mod=MOD) {base%=mod;ll ans=1;while(exp){if(exp&1LL) ans=(ans*base)%mod;exp>>=1LL,base=(base*base)%mod;}return ans;}
 
 

ll dp[3003][3003];
ll p[3003][3003];

int main(){
      sync;
      ll n;
      cin>>n;
      string s;
      cin>>s;
      
      dp[1][1]=1;
      p[1][1]=1;
      for(int i=2;i<=n;i++){
           for(int j=1;j<=i;j++){
               if(s[i-2]=='<'){
                    dp[i][j]=mod(dp[i][j]+p[i-1][j-1]);
               }
               else{
                    dp[i][j]=mod(MOD+dp[i][j]+(p[i-1][i-1]- p[i-1][j-1]));
               }
           }

           for(int j=1;j<=i;j++){
                p[i][j]=mod(p[i][j-1]+dp[i][j]);
           }
           
      }
         cout<<p[n][n]<<endl;
}