#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, a = 0, x = 0, total = 0;
  cin >> N;
  a = N;
  while(N){
    x = N % 10;
    total += x;
    N /= 10;
  }

  if(a % total == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}