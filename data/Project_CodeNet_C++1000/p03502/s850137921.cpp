#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int M = N;
  int sum_dig = 0;
  while(N != 0){
    sum_dig += N % 10;
    N /= 10;
  }
  if(M % sum_dig == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
