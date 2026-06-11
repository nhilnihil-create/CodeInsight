#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin>>s;
  int ans=0;
  ans+=s[0]-1-'0';
  ans+=9*(s.size()-1);
  int ans0=0;
  rep(i,s.size()){
    ans0+=s[i]-'0';
  }
  ans=max(ans,ans0);
  cout<<ans<<endl;
}