#include <bits/stdc++.h>
using namespace std;

int main() { 
  int N, A, B;
  cin >> N >> A >> B;
  int c = 0;

  if(N*A<B){
    c = N * A;


  }
  else{
    c = B;
  }
  cout << c << endl;
}