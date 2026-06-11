#include <bits/stdc++.h>
using namespace std;

int f(int n){
 if(n % 2 == 0) return n / 2;
  else return 3 * n + 1;
}

int main(void){
  int X, Y;
  cin >> X >> Y;
  cout << X + Y / 2;
  return 0;
}