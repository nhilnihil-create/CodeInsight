#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main() {
  int n,m,ans; cin>>n;
  map<string,int> a;
  rep(i,n){
    string s; cin>>s; a[s]++;
  }
  cin>>m;
  rep(i,m){
    string s; cin>>s; a[s]--;
  }
  for(auto x:a) ans=max(ans,x.second);
  cout<<ans<<endl;
}