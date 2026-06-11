#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s,t;cin>>s>>t;
  rep(i,s.size()){
    s=s.substr(1)+s[0];
  if(s==t){
    cout<<"Yes"<<endl;
    return 0;
  }
  }
  cout<<"No"<<endl;
}
  