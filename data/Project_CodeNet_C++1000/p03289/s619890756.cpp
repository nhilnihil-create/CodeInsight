#include <bits/stdc++.h>
using namespace std;

int main() {
string S; cin>>S;
  int K=0;
  if(S.at(0)=='A')
    K++;
  int G=0;// Cのかず
  for(int i=2; i<S.size()-1; i++){
    if(S.at(i)=='C')
      G++;
  }
  if(G==1&&S.at(0)!='C'&&S.at(1)!='C'&&S.at(S.size()-1)!='C') K++;
  int QA=0;
  for(int i=0; i<S.size();i++){
if(isupper(S.at(i))&&S.at(i)!='A'&&S.at(i)!='C'){
  QA++;
}
    else continue;
}
  
  if(QA==0)
    K++;
  if(K==3)
    cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
}
