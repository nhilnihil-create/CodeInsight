#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b;cin>>a>>b;
  string s;cin>>s;
  bool ans=true;
  rep(i,a+b+1){
    if(i==a){
      if(s[i]!='-')ans=false;
    }
    else {
      if(s[i]=='-')ans=false;
    }
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}