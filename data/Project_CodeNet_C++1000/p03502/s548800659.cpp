#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M, sum=0, num;
  cin >> N;
  M = N;
  
  while(M >= 1){
    num = M % 10;
    sum += num;
    M = (M -num) / 10;
  }
  if(N % sum == 0){
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}