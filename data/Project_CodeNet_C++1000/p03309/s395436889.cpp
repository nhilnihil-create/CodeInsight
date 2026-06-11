#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  ll vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
    vec[i]-=i+1;
  }
  sort(vec,vec+n);
  ll ans=1e15;
  if(n%2==0){
    for(int j=n/2-1;j<=n/2;j++){
      ll sum=0;
      for(int i=0;i<n;i++){
        sum+=abs(vec[i]-vec[j]);
      }
      ans=min(ans,sum);
    }
    ll x=(vec[n/2-1]+vec[n/2])/2;
    for(int j=x-1;j<=x+1;j++){
      ll sum=0;
      for(int i=0;i<n;i++){
        sum+=abs(vec[i]-j);
      }
      ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
  }
  for(int j=n/2-1;j<=n/2+1;j++){
    ll sum=0;
    for(int i=0;i<n;i++){
      sum+=abs(vec[i]-vec[j]);
    }
    ans=min(ans,sum);
  }
  cout<<ans<<endl;
}