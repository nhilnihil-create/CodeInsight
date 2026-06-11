#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, a, b, f;
  cin >> N;
  a = N;
  while(a >= 10){
    b = a % 10;
    a = (a - b) / 10;
    f += b;
  }
  f += a;
  if(N % f == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
