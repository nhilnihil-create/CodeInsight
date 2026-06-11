#include <bits/stdc++.h>
using namespace std;

int main(){
  string S,T="keyence";
  cin>>S;
  int k=0,i=0,l=0;
  for(;i<S.size() && i<7;i++)
    if(S.substr(0,i)!=T.substr(0,i))
      break;
  for(;l<S.size() && l<7;l++)
    if(S.substr(S.size()-1-l,l)!=T.substr(T.size()-1-l,l))
      break;
  if(i+l-1<7)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
}