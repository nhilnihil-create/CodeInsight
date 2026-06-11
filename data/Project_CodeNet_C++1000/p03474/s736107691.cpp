#include <iostream>
#include <string>
using namespace std;
int main() {
  int a,b;
  bool flag=true;
  cin>>a>>b;
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(i<a){
      if(!(('0'<=s[i])&&('9'>=s[i]))){
        flag=false;
      }
    }
    if(a<i){
      if(!(('0'<=s[i])&&('9'>=s[i]))){
        flag=false;
      }
    }
    if(a==i){
      if(s[i]!='-'){
        flag=false;
      }
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}