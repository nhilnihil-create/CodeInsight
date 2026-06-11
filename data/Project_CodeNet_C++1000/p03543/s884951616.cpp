#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b, c, d;
  cin >> N;

  a = N % 10;
  b = (N / 10) % 10;
  c = (N / 100) % 10;
  d = N / 1000;
  
  if(b == c){
    if((a == b) || (c == d))
      cout << "Yes" << endl;
    else
      cout << "No" <<endl;
  }else{
    cout << "No" << endl;
  }
}