#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
int main() {
  int ans=700;
  string s;
  cin>>s;
  rep(i,s.size()) if(s[i]=='o') ans+=100;
  cout<<ans<<endl;
}