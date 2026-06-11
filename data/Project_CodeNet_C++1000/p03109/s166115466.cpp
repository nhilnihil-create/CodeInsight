#include<bits/stdc++.h>
using namespace std;
int main(){
  string S,Y,M,D;
  cin>>S;
  for(int i=0;i<4;i++){
    Y=Y+S.at(i);
  }
  for(int i=5;i<7;i++){
    M=M+S.at(i);
  }
  for(int i=8;i<10;i++){
    D=D+S.at(i);
  }
  int y=stoi(Y);
  int m=stoi(M);
  int d=stoi(D);
  bool flag=true;
  if(y>=2020){
    flag=false;
  }
  else if(y==2019&&m>=5){
    flag=false;
  }
  if(flag==false){
    cout<<"TBD"<<endl;
  }
  else{
    cout<<"Heisei"<<endl;
  }
}
