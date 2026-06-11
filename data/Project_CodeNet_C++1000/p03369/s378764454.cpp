#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin>>S;
  int M=700;
  for(int X=0;X<3;X++){
    if(S[X]=='o'){
      M+=100;
    }
  }
  cout<<M<<endl;
}