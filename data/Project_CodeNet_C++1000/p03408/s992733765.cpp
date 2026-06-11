#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;cin>>n;
  vector<string> s(n);
  rep(i,n)cin>>s[i];
  int m;cin>>m;
  vector<string> t(m);
  rep(i,m)cin>>t[i];
  int ans=0;
  rep(i,n){
    int cnt=0;
    for(int j=i;j<n;j++){
      if(s[i]==s[j])cnt++;
    }
    rep(k,m){
      if(s[i]==t[k])cnt--;
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}