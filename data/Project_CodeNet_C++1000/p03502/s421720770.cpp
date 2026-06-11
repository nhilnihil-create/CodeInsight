#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int sum = 0;
  cin >> N;
  int A = N;
  for (int i = 1; i < 9; i++){
    int B = A % 10;
    sum += B;
    A -= B;
    A /= 10;
  }
  
  if (N % sum == 0){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}