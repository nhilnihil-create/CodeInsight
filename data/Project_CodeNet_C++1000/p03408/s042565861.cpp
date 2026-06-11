#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int n,m;
  cin>>n;
  vector<string>s(n);
  rep(i,n)cin>>s[i];
  
  cin>>m;
  vector<string>t(m);
  rep(i,m)cin>>t[i];
  int ans=0;
  
  rep(i,n){
    int score=0;
    rep(j,n)if(s[i]==s[j])score++;
    rep(j,m)if(s[i]==t[j])score--;
    ans=max(ans,score);
  }
  cout<<ans<<endl;
  return 0;
}