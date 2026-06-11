#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dp[10005][5005];
ll use[]={0,2,5,5,4,5,6,3,7,6};
int main(){
  for(int i=0;i<10005;i++){
    for(int j=0;j<5005;j++) dp[i][j]=false;
  }
  dp[0][0]=true;
  ll n,m;
  cin>>n>>m;
  vector<ll> v;
  for(int i=0;i<m;i++){
    ll a;
    cin>>a;
    v.push_back(a);
  }
  sort(v.begin(),v.end(),greater<ll>());
  for(int i=0;i<n;i++){
    for(int j=0;j<5000;j++){
      if(dp[i][j]){
        for(int k=0;k<m;k++){
          if(i+use[v[k]]<10005) dp[i+use[v[k]]][j+1]=true;
        }
      }
    }
  }

  vector<ll> vec;
  int kt;
  for(kt=5004;kt>=0;kt--){
    if(dp[n][kt]) break;
  }
  vector<ll> ans;
  ll ks=n;

  for(;kt>0;kt--){
    for(int i=0;i<m;i++){
      if(ks-use[v[i]]>=0){
        if(dp[ks-use[v[i]]][kt-1]){
          ans.push_back(v[i]);
          ks-=use[v[i]];
          break;
        }
      }
    }
  }
  for(int i=0;i<ans.size();i++) cout<<ans[i];
  cout<<endl;
}
