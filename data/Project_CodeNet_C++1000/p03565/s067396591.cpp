#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  string S,T;
  cin>>S>>T;
  string answer;
  int num=0;
  if(T.size()<=S.size()){
    for(int i=S.size()-T.size();i>=0;i--){
      int judge=0;
      for(int j=0;j<T.size();j++){
        if(S[i+j]==T[j]||S[i+j]=='?') judge++;
      }
      if(judge==T.size()){
        answer=S.substr(0,i)+T+S.substr(i+T.size(),S.size()-T.size()-i);
        num++;
        i-=100;
      }
    }
  }
  if(num==0) cout<<"UNRESTORABLE"<<endl;
  else{
    for(int i=0;i<S.size();i++){
      if(answer[i]=='?') answer[i]='a';
    }
    cout<<answer<<endl;
  }
  
  return 0;
}