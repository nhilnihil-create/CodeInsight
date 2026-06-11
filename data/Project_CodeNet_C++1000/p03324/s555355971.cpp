#include <bits/stdc++.h>
using namespace std;

int main() {
  int D;
  string N;
  cin>>D>>N;
  if(N=="100"){
    cout<<101;
  }
  else{
    cout<<N;
  }
  for(int X=0;X<D;X++){
    cout<<"00";
  }
}
