#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin>>n>>s;
  int count=0;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='R'){
      count++;
    }
  }
  if(s.size()-count<count){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  
}
