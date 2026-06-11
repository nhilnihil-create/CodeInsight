#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;string s;cin>>n>>s;
  int R=0,B=0;
  rep(i,s.size()){
    if(s[i]=='R')R++;
    else B++;
  }
  if(R>B)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}