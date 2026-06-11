#include <bits/stdc++.h>
using namespace std;
int main() {
  string s,t; cin>>s>>t;
  for(int i=0; i<s.length(); i++){
    if(s.substr(i+1)+s.substr(0,i+1)==t){
      cout<<"Yes";
      return 0;
    }
  }
  cout<<"No";
}