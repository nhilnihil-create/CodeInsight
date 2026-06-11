#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int n=s.size();
  if(n==2)cout<<s<<endl;
  else {
    rep(i,n){
      cout<<s[n-i-1];
      if(i==n-1)cout<<endl;
    }
  }
}