#include <bits/stdc++.h>
using namespace std;
int main(){
  string S,T;
  cin>>S>>T;
  int N=S.size(),a=0;
  for(int i=0;i<N;i++){
    string A,B;
    for(int j=0;j<i;j++){
      A.push_back(S.at(j));
    }
    for(int j=i;j<N;j++){
      B.push_back(S.at(j));
    }
    string C=B+A;
    if(C==T){
      a=1;
      break;
    }
  }
  if(a==0)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
}