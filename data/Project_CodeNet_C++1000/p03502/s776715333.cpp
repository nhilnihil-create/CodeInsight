#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,sum=0;
  cin >> N;
  int tmp = N;
  while(N>0){
    sum += N % 10;
    N = N /10;
  }
  if(tmp % sum ==0)
    printf("Yes");
  else
    printf("No");
}