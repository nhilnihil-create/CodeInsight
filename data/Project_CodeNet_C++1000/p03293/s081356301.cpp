#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  
  int n=s.size();
  s=s+s;
  
  bool b=false;
  rep(i,n){
    bool c=true;
    for(int j=0;j<n;j++){
      if(s[j+i]!=t[j]) c=false;
    }
    if(c) b=true;
  }
  if(b) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  return 0;
}