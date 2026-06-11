#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string F;
  int U=0;
  cin>>F;
  if(F=="10"||F=="100000"||F=="100"||F=="1000"||F=="10000"){
    cout<<10<<endl;
  }
  else{
    for(int X=0;X<F.size();X++){
      U+=(int)F[X]-'0';
    }
    cout<<U<<endl;
  }
}