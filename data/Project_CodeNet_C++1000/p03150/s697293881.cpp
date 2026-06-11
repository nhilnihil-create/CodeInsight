#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int N=S.size();
  string T="keyence";
  int count=0;
  for(int i=0;i<7;i++){
    if(S.at(i)==T.at(i)){
      count++;
    }else{
      break;
    }
  }
  for(int i=6;i>=0;i--){
    if(S.at(N-7+i)==T.at(i)){
      count++;
    }else{
      break;
    }
  }
  
  if(count>=7){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
  