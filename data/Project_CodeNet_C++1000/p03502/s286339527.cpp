#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,G = 0; 
  cin >> N;
  int N2 = N;
  for (int i = 0; i < 9; i++){
    G += N % 10;
    N = N / 10;
  }
  if (N2 % G == 0){
    cout << "Yes"<< endl;
  }else{
    cout << "No" << endl; 
  }
}