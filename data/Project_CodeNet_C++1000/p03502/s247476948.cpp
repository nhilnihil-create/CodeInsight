#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int a;
  a = 0;
  int b;
  b = N;
  int c = 0;
  for (int i=0; i < 9; i++){
    c = b;
    for (int j=0; j < 8-i; j++){
  c = c / 10;
    }
  a += c;
    for ( int k=0; k < 8-i; k++){
    c = 10 * c;
  }
    b = b - c;
  }
  while (N > 0){
    N = N - a;
  }
  if (N == 0){
  cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}