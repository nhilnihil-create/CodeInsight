#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n;
  cin>>n;
  vector<P> ans;
  if(n%2==0){
    for(int i=1; i<=n; i++){
      for(int j=i+1; j<=n; j++){
        if(i+j!=n+1) ans.push_back(make_pair(i,j));
      }
    }
  }else{
    for(int i=1; i<=n; i++){
      for(int j=i+1; j<=n; j++){
        if(i+j!=n) ans.push_back(make_pair(i,j));
      }
    }
  }
  cout<<ans.size()<<endl;
  for(auto p : ans){
    cout<<p.first<<" "<<p.second<<endl;
  }
}