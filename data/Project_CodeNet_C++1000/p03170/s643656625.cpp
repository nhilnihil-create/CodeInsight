#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define repr(i,n) for(int i{n};i-->0;)

signed main(){

  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(auto& ai:a)cin>>ai;

  vector<int> win(3e5);
  rep(i,k){
    if(win[i])continue;
    for(auto ai:a)win[i+ai] = 1;
  }
  cout<<(win[k]?"First":"Second")<<endl;

}