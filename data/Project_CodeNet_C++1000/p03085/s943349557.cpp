#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++) {
    if(s.at(i)=='A') {
      s.at(i)='T';
    }
    else if(s.at(i)=='T') {
      s.at(i)='A';
    }
    else if(s.at(i)=='G') {
      s.at(i)='C';
    }
    else{
      s.at(i)='G';
    }
  }
  cout<<s<<endl;
  return 0;
}