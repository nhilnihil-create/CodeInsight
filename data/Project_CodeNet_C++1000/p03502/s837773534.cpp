#include <bits/stdc++.h>
using namespace std;

int main() {
 int X, N, Z;
 X = 0; 
 cin >> N;
 Z = N; 
  for(int i = 0; i < 9; i++){
  X += N % 10;
  N = N / 10;
  }
  if((Z % X) != 0){
  cout << "No" << endl;
  }else{
  cout << "Yes" << endl;
  }
}