#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  
  string s,t;
  cin>>s>>t;
  bool flag;
  for(size_t i=0;i<=s.length()-1;i++){
  
    flag=1;
    for(size_t j=0;j<=s.length()-1;j++){
    
      if(s[(j+i)%(s.length())]!=t[j]){
      
        flag=0;
        break;
      }
    }
    if(flag==1){
    
      cout<<"Yes";
      return 0;
    }
  }
  cout<<"No";
  return 0;
}