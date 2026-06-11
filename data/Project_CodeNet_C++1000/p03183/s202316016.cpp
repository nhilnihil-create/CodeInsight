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
 



vector<ipii> p;
ll dp[1003][20004];

bool comp(ipii a,ipii b){
     return (a.ft+a.sd.ft)<(b.ft+b.sd.ft);
}


int main(){
      sync;
      ll n;
      cin>>n;
      int f=0;
      for(int i=0;i<n;i++){
            ll w,s,v;
            cin>>w>>s>>v;
            if(s>10000||w>10000) f=1;
            p.pb({s,{w,v}});
      }
       
        if(f){
            cout<<"Hold ON!"<<endl;
            return 0;
        }
        sort(all(p),comp);
        ll ans=0;
        for(int i=0;i<=20004;i++){
               dp[0][i]=(p[0].sd.ft<=i?p[0].sd.sd:0);
        }
        for(int i=1;i<n;i++){
             for(int j=0;j<=20000;j++){
                  if(j==0){
                       dp[i][j]=0;continue;
                  }
                  dp[i][j]=dp[i-1][j];
                  if(p[i].sd.ft<=j){
                        dp[i][j]=max(dp[i][j],dp[i-1][min(j-p[i].sd.ft,p[i].ft)]+p[i].sd.sd);
                  }
             }
        }

        for(int i=0;i<=20000;i++) ans=max(ans,dp[n-1][i]);
        cout<<ans<<endl; 
}