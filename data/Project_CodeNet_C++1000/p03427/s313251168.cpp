#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  
  string N;
  cin>>N;
  int ans=0;
  vector<int>keta(N.length());
  for(size_t i=0;i<=N.length()-1;i++){
  
    keta[i]=N[i];
  }
  bool flag=0;
  for(size_t i=1;i<=N.length()-1;i++){
  
    if(keta[i]!=57){
    
      flag=1;
      break;
    }
  }
  if(flag==0){
  
    cout<<keta[0]+(N.length()-1)*9-48<<endl;
  }
  else{
  
    cout<<keta[0]-1+(N.length()-1)*9-48<<endl;
  }
  return 0;
}