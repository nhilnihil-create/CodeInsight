#include<bits/stdc++.h>
using namespace std;

int main(){
  string S, T;
  cin >> S >> T;
  string A="";
  for(int i=0; i<S.size(); i++){
    int p=A.size();
    int e=0;
    for(int j=0; j<p; j++){
      if(S.at(i)==A.at(j)){
        S.at(i)='a'+j;
        e=1;
        break;
      }
    }
    if(e==0){
      A.push_back(S.at(i));
      S.at(i)='a'+p;
    }
  }
  A="";
  for(int i=0; i<T.size(); i++){
    int p=A.size();
    int e=0;
    for(int j=0; j<p; j++){
      if(T.at(i)==A.at(j)){
        T.at(i)='a'+j;
        e=1;
        break;
      }
    }
    if(e==0){
      A.push_back(T.at(i));
      T.at(i)='a'+p;
    }
  }
  if(S==T){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}