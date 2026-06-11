#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  string ans="AC";
  if(S.at(0)!='A'){
    ans="WA";
  }
  int test=0;
  for(int i=1;i<S.size();i++){
    if(isupper(S.at(i))){
      if(i==1||i==S.size()-1||S.at(i)!='C'){
        ans="WA";
      }
      test++;
    }
       }
       if(test!=1){
         ans="WA";
       }
       cout<<ans<< endl;
       }
        
