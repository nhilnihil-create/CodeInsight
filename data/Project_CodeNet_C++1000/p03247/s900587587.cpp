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

  ll x[n+1]={};
  ll y[n+1]={};
  ll z[n+1]={};

  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
    z[i]=abs(x[i])+abs(y[i]);
  }

  for(int i=0;i<n;i++){
    if(z[i]%2!=z[0]%2){
      cout<<"-1"<<endl;
      return 0;
    }
  }

  vector<ll> d;
  for(int i=30;i>=0;i--){
    d.push_back(1<<i);
  }
  if(z[0]%2==0) d.push_back(1ll);

  int m=d.size();
  cout<<m<<endl;
  for(int i=0;i<m-1;i++) cout<<d[i]<<" ";
  cout<<d[m-1]<<endl;

  for(int i=0;i<n;i++){
    ll u=x[i]+y[i];
    ll v=x[i]-y[i];
    vector<char> ans;

    for(int j=0;j<m;j++){
      if(u>=0){
        if(v>=0){
          ans.push_back('R');
          u-=d[j];
          v-=d[j];
        }else{
          ans.push_back('U');
          u-=d[j];
          v+=d[j];
        }
      }else{
        if(v>=0){
          ans.push_back('D');
          u+=d[j];
          v-=d[j];
        }else{
          ans.push_back('L');
          u+=d[j];
          v+=d[j];
        }
      }
    }

    for(int j=0;j<m;j++) cout<<ans[j];
    cout<<endl;
  }

  return 0;
}
