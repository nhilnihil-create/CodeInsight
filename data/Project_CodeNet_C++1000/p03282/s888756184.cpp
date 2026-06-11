#include<iostream>
#include<string>
using namespace std;
int main(){

  string S;
  long long K;
  cin>>S>>K;
  long long count=0;
  for(size_t i=0;i<=S.length()-1;i++){
  
    if(S[i]=='1'){
    
      count++;
      if(count==K){
      
        cout<<1;
        return 0;
      }
    }
    else{
    
      cout<<S[i];
      return 0;
    }
  }
  return 0;
}