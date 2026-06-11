#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
ll n,ans=0;

void dfs(ll x){
  if(n>=x ){
    set<int> s; ll y=x;
    while(y%10!=0){
      s.insert(y%10); y/=10;
    }
    if(s.size()==3){ans++;}
  }
  if(n<x){return;}
  dfs(x*10+3);
  dfs(x*10+5);
  dfs(x*10+7);
}
int main() {
  cin>>n;
  dfs(3);dfs(5);dfs(7);
  cout<<ans;
}