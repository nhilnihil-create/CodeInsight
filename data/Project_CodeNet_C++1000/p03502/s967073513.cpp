#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int M = N;
  int ketaSum = 0;
  
  while(M > 0){
    ketaSum += M % 10;
    M /= 10;
  }
  
  if(N % ketaSum == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}