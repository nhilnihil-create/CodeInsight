#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int Y=0,M=0;
  for(int i=0;i<4;i++){
    Y*=10;
    Y+=S[i]-'0';
  }
  for(int i=5;i<7;i++){
    M*=10;
    M+=S[i]-'0';
  }
  if(Y<2019){
    cout<<"Heisei"<<endl;
  }
  else if(M<5&&Y==2019){
    cout<<"Heisei"<<endl;
  }
  else{
    cout<<"TBD"<<endl;
  }
}

