//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e9+7;
ll INF=1e10;

int main(){
      ll n,m; cin>>n>>m;
  if(n==1){
    cout<<m<<endl;
    return 0;
  }
  ll ans=0;
  for(ll i=1;i<=sqrt(m);i++){
      if(m%i==0){
          if((m/i)*n<=m){
              ans=max(ans,m/i);
          }
          else if(i*n<=m){
              ans=max(ans,i);
          }
      }
  }
  cout<<ans<<endl;
}

























































































