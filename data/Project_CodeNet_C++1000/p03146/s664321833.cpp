#include<bits/stdc++.h>
using namespace std;

int func(int N){
  if(N%2==0){
    return N/2;
  }
  else{
    return 3*N+1;
  }
}

int main(){
  int S;
  cin >> S;
  vector<int> A(100000000);
  A.at(0)=S;
  for(int i=1;i<10000000;i++){
    A.at(i)=func(A.at(i-1));
  }
  bool a=false;
  for(int i=0;i<10000000;i++){
    for(int j=i+1;j<10000000;j++){
      if(A.at(i)==A.at(j)){
        cout << j+1 << endl;
        a=true;
        break;
      }
    }
    if(a){
      break;
    }
  }
}  