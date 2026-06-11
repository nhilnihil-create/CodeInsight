#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;
  cin>>S;
  
  int check_1=0;
  
  int check_2=0;
  
  
  for(int i=0;i<S.size();i++){
    if(i%2==0){
      if(S[i]=='1'){
        check_1++;
      }
    }
    else if(i%2==1){
      if(S[i]=='0'){
        check_1++;
      }
    }
  }
  
  for(int i=0;i<S.size();i++){
    if(i%2==0){
      if(S[i]=='0'){
        check_2++;
      }
    }
    else{
      if(S[i]=='1'){
        check_2++;
      }
    }
  }
  
  cout<<min(check_1,check_2)<<endl;
}