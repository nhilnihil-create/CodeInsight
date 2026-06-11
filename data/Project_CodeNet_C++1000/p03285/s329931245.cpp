#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin >> N;
  A=N/4,B=N/7;
  bool a=false;
  for(int i=0;i<A+1;i++){
    for(int j=0;j<A+1;j++){
      if(4*i+7*j==N){
        a=true;
        break;
      }
    }
  }
  if(a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}