#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int cnt=0;
  rep(i,s.size()){
    if(s[i]=='o')cnt++;
  }
  if(15-s.size()+cnt>=8)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}