#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> x(m);
  rep(i,m){
    cin>>x[i];
  }
  sort(x.begin(),x.end());
  vector<int> div(m-1);
  rep(i,m-1){
    div[i]=x[i+1]-x[i];
  }
  sort(div.begin(),div.end());
  int ans=0;
  if(n<m){
    rep(i,n-1){
      div.pop_back();
    }
    for(auto p : div){
      ans+=p;
    }
  }
  cout<<ans<<endl;
}

