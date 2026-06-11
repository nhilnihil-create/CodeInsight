#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
2文字以上。aaもだめか
abc
abcab
総数くらい？
aaabbc
a
ab
abc
abcabcabc...のかたちしかないっぽい
*/
int main(){
  string S; cin>>S;
  ll sz=S.size(), A,B,C;
  A=B=C=0;
  for(int i=0; i<sz; i++){
    if(S[i]=='a')
      A++;
    else if(S[i]=='b')
      B++;
    else
      C++;
  }
  if(abs(A-B)>1 || abs(B-C)>1 || abs(A-C)>1)
    cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}