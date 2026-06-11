#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n;cin>>n;
  vector<string> w(n);
  rep(i,n)cin>>w[i];
  bool ans=true;
  rep(i,n-1){
    if(w[i][w[i].size()-1]!=w[i+1][0])ans=false;
            }
  rep(i,n){
    for(int j=i+1;j<n;j++){
      if(w[i]==w[j])ans=false;
    }
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}