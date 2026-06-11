#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  ll a[n+1]={};
  cin>>a[1];
  ll s=a[1],t=a[1];
  int ss=1,tt=1;
  for(int i=2;i<=n;i++){
    cin>>a[i];
    if(s>a[i]){
      s=a[i];
      ss=i;
    }
    if(t<a[i]){
      t=a[i];
      tt=i;
    }
  }
  vector<pair<ll,ll>> v;
  if(t+s>0){
    for(int i=1;i<=n;i++){
      v.push_back(make_pair(tt,i));
    }
    for(int i=1;i<n;i++){
      v.push_back(make_pair(i,i+1));
    }
  }else{
    for(int i=1;i<=n;i++){
      v.push_back(make_pair(ss,i));
    }
    for(int i=n;i>1;i--){
      v.push_back(make_pair(i,i-1));
    }
  }
  cout<<2*n-1<<endl;
  for(int i=0;i<2*n-1;i++) cout<<v[i].first<<" "<<v[i].second<<endl;
  return 0;
}
