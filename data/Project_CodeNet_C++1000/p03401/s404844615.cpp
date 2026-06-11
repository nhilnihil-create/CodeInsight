#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
int main(){
  int n;cin>>n;
  vector<int> a(n+1);
  ll sum=0;
  a[0]=0;
  rep(i,n+1){
    if(i==0)continue;
    cin>>a[i];
    sum+=abs(a[i-1]-a[i]);
  }
  sum+=abs(a[0]-a[n]);
  // cout<<sum<<endl;
  rep(i,n){
    if(i==0)continue;
    int mi=abs(a[i-1]-a[i])+abs(a[i+1]-a[i]);
    int pl=abs(a[i-1]-a[i+1]);
    cout<<sum-mi+pl<<endl;
  }
  cout<<sum-abs(a[n-1]-a[n])-abs(a[0]-a[n])+abs(a[0]-a[n-1])<<endl;
}