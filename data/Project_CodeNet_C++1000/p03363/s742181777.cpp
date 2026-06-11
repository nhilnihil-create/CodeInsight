#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  ll vec[n];
  ll sum[n+1];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  map<ll,ll> ma;
  sum[0]=0;
  ma[sum[0]]++;
  for(int i=0;i<n;i++){
    sum[i+1]=sum[i]+vec[i];
    ma[sum[i+1]]++;
  }
  ll ans;
  for(int i=0;i<n;i++){
    ans+=(ma[sum[i]]*(ma[sum[i]]-1))/2;
    ma[sum[i]]=0;
  }
  cout<<ans<<endl;
}