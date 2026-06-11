#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b; cin>>a>>b;
  string s; cin>>s;
  for(char c:s.substr(0,a)) if('0'>c||c>'9'){
    cout<<"No"; return 0;
  }
  if(s.substr(a,1)!="-"){
    cout<<"No"; return 0;
  }
  for(char c:s.substr(a+1,b)) if('0'>c||c>'9'){
    cout<<"No"; return 0;
  }
  cout<<"Yes";
}