#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);


int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> w(n+1);
  vector<int> e(n+1);

  rep(i,n){
    if(s[i]=='W'){
      w[i+1]=w[i]+1;
    }
    else {
      w[i+1]=w[i];
    }
  }
  
  rep(i,n){
    if(s[i]=='E'){
      e[i+1]=e[i]+1;
    }
    else {
      e[i+1]=e[i];
    }
  }
  int ans = n;
  rep(i,n){
    ans=min(ans,w[i]+e[n]-e[i+1]);
  }

  cout << ans << endl;

  return 0;
}