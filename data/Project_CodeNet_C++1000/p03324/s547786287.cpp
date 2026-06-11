#include<bits/stdc++.h>
using namespace std;

//100で割れる回数を確かめる関数
int func(int X){
  if(X%100!=0){
    return 0;
  }
  return func(X/100)+1;
}

int main(){
  int D,N;
  cin >> D >> N;
  int count=0;
  for(int i=1;;i++){
    if(func(i)==D){
      count++;
    }
    if(count==N){
      cout << i << endl;
      break;
    }
  }
}