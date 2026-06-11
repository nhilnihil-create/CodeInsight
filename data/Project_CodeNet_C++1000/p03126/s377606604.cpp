#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n,m;cin>>n>>m;
  vector<int> vec(m);
  rep(i,n){
    int k;cin>>k;
    rep(j,k){
      int a;cin>>a;
      vec[a-1]++;
    }
  }
  int cnt=0;
  rep(i,m){
    if(vec[i]==n)cnt++;
  }
  cout<<cnt<<endl;
}