#include<iostream>
#include<cmath>
int main(){
  long long int N,P;
  std::cin >> N >> P;
  long long int i=3,k,result=1;

  if(N==1){
    std::cout << P;
    return 0;
  }

  if(P>=std::pow(2,N)){
    k=std::pow(2,N);
    while(P%k==0){
      result = result * 2;
      P= P/std::pow(2,N);
    }
  }


  while(P>=std::pow(i,N)){
    k=std::pow(i,N);
    while(P%k==0){
      result = result * i;
      P= P/std::pow(i,N);
    }
    i+=2;
  }

  std::cout << result;
  return 0;
}
