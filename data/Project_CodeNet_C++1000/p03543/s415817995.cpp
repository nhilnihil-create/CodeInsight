#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b,c,d,x,y;
  cin >> n;

  x = 0;
  y = 0;
  a = n / 1000;
  b = (n % 1000) / 100;
  c = (n % 100) / 10;
  d = (n % 10);
  
  if (a == b) {
    x = x + 1;
  } 
  if (b == c) {
    x = x + 1;
    if (x >= 2){
      y = 1;
    }
  } else {
    x = 0;
  }
  if (c == d) {
    x = x + 1;
    if (x >= 2){
      y = 1;
    }
  }
  
  if (y == 1) {
	cout << "Yes" << endl;
   } else {
	cout << "No" << endl;
     
  }
}