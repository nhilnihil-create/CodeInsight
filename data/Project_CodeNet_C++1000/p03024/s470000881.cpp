#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int count=0;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='x'){
      count++;
    }
  }
  if(count<=7){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  
      
}