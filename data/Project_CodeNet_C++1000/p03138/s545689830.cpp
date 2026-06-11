#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
#define ll long long
using namespace std;
void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void  solve(){
  ll n,k;
     cin>>n>>k;
     ll a[n];
     for(int i=0;i<n;i++)cin>>a[i];
     int ct[60];
     memset(ct,0,sizeof(ct));
     for(int i=0;i<n;i++){
          ll t=a[i];
          for(int j=0;j<50;j++){
               ct[j]+=t%2;
               t/=2;
          }
     }
     ll res=0LL,tmp=0LL;
     for(int j=59;j>=0;j--){
          int count1=ct[j];
          if(count1>=n-count1){
               res+=count1*(1LL<<j);
          }
          else{
               ll ty=(tmp+(1LL<<j));
               if(ty<=k){
                    tmp=ty;
                    res+=(n-count1)*(1LL<<j);
               }
               else{
                    res+=(count1)*(1LL<<j);
               }
          }
     }
     cout<<res;
}
int main(){
    optimizeIO();
    solve();
}
