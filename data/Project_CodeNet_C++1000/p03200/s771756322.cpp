#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  long long K=0;
  int M=0;
  long long H=0;
  cin>>S;
  for(int X=0;X<S.size();X++){
    if(S[X]=='W'){
      K+=X;
      H+=M;
      M++;
    }
  }
  cout<<K-H<<endl;
}