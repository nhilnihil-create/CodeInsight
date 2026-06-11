#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,N;
  cin >> N;
  A = 100/4;
  B = 100/7;
  bool result=0;
  for(int i=0;i<=A;i++){
    for(int j=0;j<=B;j++){
      if(4*i+7*j==N){
        result=1;
        break;
      }
    }
  }
  if(result==true){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}