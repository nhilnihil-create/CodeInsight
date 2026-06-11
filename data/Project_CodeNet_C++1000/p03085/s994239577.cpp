#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string B;
  cin>>B;
  for(int X=0;X<B.size();X++){
    if(B[X]=='A'){
      B[X]='T';
    }
    else if(B[X]=='C'){
      B[X]='G';
    }
    else if(B[X]=='T'){
      B[X]='A';
    }
    else{
      B[X]='C';
    }
  }
  cout<<B<<endl;
}
