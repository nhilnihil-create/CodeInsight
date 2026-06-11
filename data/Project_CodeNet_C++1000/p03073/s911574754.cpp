#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int ans=s.size(),n=s.size();
  rep(i,2){
    int cnt=0;
    rep(j,n){
      if(j%2==0&&s[j]!=(char)(i+'0'))cnt++;
      if(j%2==1&&s[j]==(char)(i+'0'))cnt++;
    }
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}