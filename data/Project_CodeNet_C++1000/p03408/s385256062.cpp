#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  vector<string> s(n);
  rep(i,n){
    cin>>s[i];
  }
  int m;
  cin>>m;
  vector<string> t(m);
  rep(i,m){
    cin>>t[i];
  }
  int max_ans=0;
  for(auto x : s){
    int ans=0;
    rep(i,n){
      if(s[i]==x)ans++;
    }
    rep(i,m){
      if(t[i]==x)ans--;
    }
    max_ans=max(max_ans,ans);
  }
  cout<<max_ans<<endl;
}
