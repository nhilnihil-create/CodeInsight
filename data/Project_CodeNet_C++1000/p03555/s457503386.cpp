#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s,t;
  cin>>s>>t;
  if(s[0]==t[2]){
    if(s[1]==t[1]){
      if(s[2]==t[0]){
        cout<<"YES"<<endl;
        return 0;
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}