#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int cnt0=0,cnt1=0;
  rep(i,s.size()){
    if(s[i]=='0')cnt0++;
    else cnt1++;
  }
  int ans=min(cnt0*2,cnt1*2);
  cout<<ans<<endl;
}