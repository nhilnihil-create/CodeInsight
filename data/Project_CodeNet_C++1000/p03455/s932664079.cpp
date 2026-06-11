#include <bits/stdc++.h>
using namespace std;

int main() {
 // ここにプログラムを追記
  int a,b,x;
  
  cin >> a >> b;
  x = a*b%2;
  
  if(x)
    cout << "Odd" << endl;
  else
    cout << "Even" << endl;
}
