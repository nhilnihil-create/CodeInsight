#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,a,b,c,d;
  cin >> n;
  d = n % 10;
  n /= 10;
  c = n % 10;
  n /= 10;
  b = n % 10;
  n /= 10;
  a = n % 10;
  if(a + b + c + d == 7){
    cout << a << "+" << b << "+" << c << "+" << d << "=7";
  }else if (a + b + c - d == 7){
    cout << a << "+" << b << "+" << c << "-" << d << "=7";
  }else if (a + b - c + d == 7){
    cout << a << "+" << b << "-" << c << "+" << d << "=7";
  }else if (a + b - c - d == 7){
    cout << a << "+" << b << "-" << c << "-" << d << "=7";
  }else if (a - b + c + d == 7){
    cout << a << "-" << b << "+" << c << "+" << d << "=7";
  }else if (a - b + c - d == 7){
    cout << a << "-" << b << "+" << c << "-" << d << "=7";
  }else if (a - b - c + d == 7){
    cout << a << "-" << b << "-" << c << "+" << d << "=7";
  }else if (a - b - c - d == 7){
    cout << a << "-" << b << "-" << c << "-" << d << "=7";
  }
}