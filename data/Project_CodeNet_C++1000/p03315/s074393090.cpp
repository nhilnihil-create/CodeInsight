#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin>>S;
  int K=0;
  for(int X=0;X<4;X++){
    if(S[X]=='+')
      K++;
    else
      K--;
  }
  cout<<K<<endl;
}