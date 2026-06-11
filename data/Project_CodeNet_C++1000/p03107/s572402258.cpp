#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin>>s;
  int zero=0, one=0;
  rep (i, s.size()){
    if(s.at(i)=='0') zero++;
    else one++;
  }
  int ans;
  if(one<=zero){
    ans=2*one;
  }
  else ans=2*zero;
  cout<<ans<<endl;
}