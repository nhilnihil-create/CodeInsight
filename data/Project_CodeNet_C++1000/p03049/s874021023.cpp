#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
簡単な気がする
ABA
BBB
AAA

BA
BA
BA
BA
=3個
BX
XA
=5個
*/
int main(){
  ll N,A=0,B=0,BA=0,AB=0; cin>>N;
  for(ll i=0; i<N; i++){
    string S; cin>>S;
    ll sz=S.size();
    if(S[0]=='B') B++;
    if(S[sz-1]=='A') A++;
    if(S[0]=='B' && S[sz-1]=='A') BA++;
    for(ll j=0; j<sz-1; j++) if(S[j]=='A' && S[j+1]=='B') AB++;
  }
  if(A==B && B==BA && A>0) AB+=BA-1;
  else AB+=min(A,B);
  cout<<AB<<endl;
}