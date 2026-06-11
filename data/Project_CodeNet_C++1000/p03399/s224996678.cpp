#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  int kekka = 0;
  
  cin >> a >> b >> c >> d;
  
  if(a >= b) kekka += b;
  else kekka += a;
  
  if(c >= d) kekka += d;
  else kekka += c;
  
  cout << kekka;
}
