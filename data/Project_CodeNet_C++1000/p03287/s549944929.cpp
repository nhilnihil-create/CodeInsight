#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,m;
  cin>>n>>m;
  int a[n];
  rep(i,0,n) cin>>a[i];
  int sum[n+1];
  sum[0]=0;
  rep(i,0,n) sum[i+1]=(sum[i]+a[i])%m;
  map<int,ll> mp;
  rep(i,0,n+1) mp[sum[i]]++;
  ll ans=0;
  for(auto p:mp){
    ans+=p.second*(p.second-1)/2;
  }
  cout<<ans<<endl;
}