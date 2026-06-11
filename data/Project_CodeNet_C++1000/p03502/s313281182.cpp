#include <bits/stdc++.h>
using namespace std;

int get(int n){
  int sum = 0;
  while(n>0){
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main(){
  int N;
  cin >> N;
  int sum = get(N);
  if(N % sum == 0){
    puts("Yes");
  }
  else{
    puts("No");
  }
}
