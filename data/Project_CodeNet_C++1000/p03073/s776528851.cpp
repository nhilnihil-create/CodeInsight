#include<iostream>
#include<string>
using namespace std;
int main(){

  string S;
  cin>>S;
  int ans1=0;
  int ans2=0;
  for(int i=0;i<=(int)(S.length()-1);i++){
  
    if(i%2==0){
    
      if(S[i]=='0')ans1++;
    }
    else{
    
      if(S[i]=='1')ans1++;
    }
  }
  for(int i=0;i<=(int)(S.length()-1);i++){
  
    if(i%2==0){
    
      if(S[i]=='1')ans2++;
    }
    else{
    
      if(S[i]=='0')ans2++;
    }
  }
  //cout<<ans1<<endl<<ans2;
  int ans=ans1<ans2?ans1:ans2;
  cout<<ans;
  return 0;
}