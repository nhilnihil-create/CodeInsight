#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;cin>>S;
  for(int X=0;X<3;X++){
    if(S[X]=='1')
      S[X]='9';
    else
      S[X]='1';
  }
  cout<<S<<endl;
}