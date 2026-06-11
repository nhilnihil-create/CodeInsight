#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int AA=0;
  int BB=0;
  string S;
  cin>>S;
  vector<char>A(S.size());
  for(int X=0;X<S.size();X++){
    if(X%2==0){
      A.at(X)='1';
    }
    else{
      A.at(X)='0';
    }
  }
  for(int X=0;X<S.size();X++){
    if(S.at(X)==A.at(X)){
      AA++;
    }
    else{
      BB++;
    }
  }
  if(AA>=BB){
    cout<<BB<<endl;
  }
  else{
    cout<<AA<<endl;
  }
}