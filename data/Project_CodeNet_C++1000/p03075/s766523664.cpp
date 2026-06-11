#include <bits/stdc++.h>
using namespace std;
int main(){
  int X;
  vector<int> T(5);
  for(int i=0;i<5;i++){
    cin>>T.at(i);
  }
  cin>>X;
  int cnt=0;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(max(T.at(j),T.at(i))-min(T.at(j),T.at(i))>X){
        cnt++;
      }
    }
  }
  if(cnt==0){cout<<"Yay!"<<endl;}
  else{cout<<":("<<endl;}
}
