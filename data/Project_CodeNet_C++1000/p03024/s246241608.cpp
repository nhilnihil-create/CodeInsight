#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int cnt=0;
  for(int i=0;i<s.length();i++){
    if(s.at(i)=='x'){
      cnt++;
    }
  }
  if(cnt>=8){
    cout<<"NO"<<endl;
  }
  else {
    cout<<"YES"<<endl;
  }
  return 0;
}


