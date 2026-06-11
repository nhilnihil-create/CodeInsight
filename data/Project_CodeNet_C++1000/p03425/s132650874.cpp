#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  string ms="MARCH";
  map<char,long long> marches{
    {'M',0},{'A',0},{'R',0},{'C',0},{'H',0}
  };
  for (int i=0;i<N;i++){
    cin >> S;
    auto it = marches.find(S[0]);
    if(it!=marches.end()) ++marches[S[0]];
  }
  long long ans=0;
  for(auto i=ms.begin();i!=ms.end();i++){
    for(auto j=i+1;j!=ms.end();j++){
      for(auto k=j+1;k!=ms.end();k++){
//        cout << *i << *j << *k << " " << marches[*i]*marches[*j]*marches[*k] << endl;
        ans+=marches[*i]*marches[*j]*marches[*k];
      }
    }
  }
  cout << ans << endl;
}