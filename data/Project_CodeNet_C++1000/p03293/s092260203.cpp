#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  string ans="No";
  for(int i=0;i<s.size();i++){
    if(t==s){
      ans="Yes";
    }
    s=s.back()+s.substr(0,s.size()-1);
  }
  cout<<ans<< endl;
}
  