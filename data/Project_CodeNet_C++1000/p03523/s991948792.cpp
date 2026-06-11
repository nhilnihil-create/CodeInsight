#include <bits/stdc++.h>
using namespace std;
int main(){
  string S,T="AKIHABARA";cin>>S;
  int i,j=0;
  for(i=0;i<9;i++){
    if(j<S.size()&&S.at(j)==T.at(i))j++;
    else if(T.at(i)!='A')break;
  }
  if(i==9&&S.size()<10)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}