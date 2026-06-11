#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,r=0,c=0;
  cin >> a >> b;
  r = (a + b) / 2;
  c = (a + b) % 2;
  
  cout << r + c << endl;
}