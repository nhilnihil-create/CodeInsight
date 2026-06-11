#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,a,b,c;
  cin >> x;
  //x = 100a + 10b + c
  c = x % 10;
  b = (x % 100 - c) / 10;
  a = (x - b * 10 - c) / 100;
  cout <<  a + b + c <<endl;
}
