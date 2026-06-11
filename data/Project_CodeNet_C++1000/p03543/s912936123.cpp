#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  cin >> n;
  a = 0;
  b = 0;
  while (n >= 1000){
    a = a + 1;
    n = n - 1000;
  }
  n = n - 100 * a;
  if (n >=10  && n <= 99) {
    n = n - 10 * a;
    if (n >=0  && n <= 9) {
      b = 1;
    }
  }
  else {
    n = n + 100 * a;
    a = 0;
    while (n >= 100){
      a = a + 1;
      n = n - 100;
    }
    n = n - 10 * a;
    if (n >= 0  && n <= 9) {
      n = n - 1 * a;
      if (n == 0) {
        b = 1;
      }
    }
  }
  if (b == 1){
  cout << "Yes";
  }
  else{
  cout << "No";
  }
}