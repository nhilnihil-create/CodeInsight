#include <bits/stdc++.h>

int main(){
  int i;
  int A,B,K;
  std::cin >> A >> B >> K;
  
  for(i=A;i<=B;i++){
    if(i<A+K||i>B-K){
      std::cout << i << std::endl;
    }
  }
}