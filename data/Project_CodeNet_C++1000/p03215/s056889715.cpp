#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
   ll n,k;
   cin>>n>>k;
   vector<ll>a(n+1);
  vector<ll>b(0);
   rep(i,n){
       ll aa;cin>>aa;
       a[i+1]=a[i]+aa;
   }
   rep(i,n){
       REP(j,i+1,n+1)b.pb(a[j]-a[i]);
   }
   vector<int>used(b.size());
   ll cnt=0;
   ll ans=0;
   for(int i=60;i>=0;i--){
       ll cn=0;
       rep(j,b.size()){
           if(used[j]==cnt){
               if((1LL<<i)&b[j])cn++;
           }
       }
       if(cn>=k){
           ans+=(1LL<<i);
           rep(j,b.size()){
               if(used[j]==cnt){
                   if((1LL<<i)&b[j]){
                       used[j]++;
                   }
               }
           }
           cnt++;
       }
   }
   cout<<ans<<endl;
}