#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

/*ll a[100],n;

ll rec(ll k,ll len){
  cout<<k<<" "<<len<<"\n";
  if(k==0) return len%2;
  ll res=-1;
  for(int i=0;i<n;i++){
    if(k>=a[i]){
      res=rec(k-a[i],len+1);
      if(res==1) break;       
    }
  }
  return res;
}*/

int main() {
  ll n,k;
  cin>>n>>k;
  ll a[n];
  bool dp[k+1];
  for(int i=0;i<=k;i++) dp[i]=false;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=1;i<=k;i++){
    for(int j=0;j<n;j++){
      if(i-a[j]<0) break;
      if(dp[i-a[j]]==false){
          dp[i]=true;
          break;
      }
    }
  }
  if(dp[k]==true) cout<<"First\n";
  else cout<<"Second\n"<<"\n";
}