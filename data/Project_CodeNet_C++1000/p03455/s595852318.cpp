#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  int amari = (a*b) % 2;
  
  //cout << amari <<endl;
  if(amari == 0)
    cout << "Even";
  else
    cout << "Odd";
}
