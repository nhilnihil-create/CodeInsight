#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >> b;
  
  if((a + b) % 2 == 1)
  {
   double A,B;
   A = a;
   B = b;
   cout << (A + B) / 2 + 0.5 << endl;
  }
  else{
  cout << (a + b) / 2 << endl;
    }
}