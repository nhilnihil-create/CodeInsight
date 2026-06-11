#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >>s;

  if(s[0]=='A'){
    s='T';
  }

  else if(s[0]=='T'){
    s='A';
  }

  else if(s[0]=='G'){
    s='C';
  }

  else if(s[0]=='C'){
    s='G';
  }

cout <<s <<endl;

}