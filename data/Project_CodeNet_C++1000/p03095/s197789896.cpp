#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  string s;
  cin >> n>>s;
  long mod=1000000007;
  
  
  vector<int>c(26);
  rep(i,n){
    c.at(s.at(i)-'a')++;
  }
  long ans=1;
  rep(i,26){  
    ans=ans*(1+c.at(i))%mod;
  }
  cout<<ans-1<<endl; 
}