#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  vector<int> d(5),r(5);
  rep(i,5){
    cin>>d[i];
    r[i]=d[i]%10;
  }
  int ld=0,r_min=10;
  rep(i,5){
    if(r[i]==0){
      continue;
    }
    if(r[i]<r_min){
      ld=i;
      r_min=r[i];
    }
  }
  int ans=0;
  rep(i,5){
    if(i==ld){
      ans+=d[i];
    }else if(r[i]==0){
      ans+=d[i];
    }else{
      ans+=d[i]/10*10+10;
     }
  }
  cout<<ans<<endl;
  
}