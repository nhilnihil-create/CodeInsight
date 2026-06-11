#include <bits/stdc++.h>

using namespace std;

int main(){

  int N, A, B, sum = 0;
  cin >> N >> A >> B;
  
  for(int i = 1;i <= N;i++){
    if(i < 10){
      if(A <= i && i <= B){
	sum += i;
      }
    }else if(i < 100){
      if(A <= i / 10 + i % 10 && i / 10 + i % 10 <= B ){
	sum += i;
      }
    }else if(i < 1000){
      if(A <= i / 100 + i / 10 % 10 + i % 10 && i / 100 + i / 10 % 10 + i % 10 <= B ){
	sum += i;
      }
    }else if(i < 10000){
      if(A <= i / 1000 + i / 100 % 10 + i / 10 % 10 + i % 10 && i / 1000 + i / 100 % 10 + i / 10 % 10 + i % 10 <= B){
      sum += i;
      }
    }else{
       if(A <= 1 && 1 <= B)
      sum += 10000;
    }

  }

  
  cout << sum << endl;
  return 0;
}
