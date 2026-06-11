#include <bits/stdc++.h>
using namespace std;

int main() {
 int a, b, c;
cin >> a >> b >> c;
  int listen = 0;
  while(true){
    if(b<a) break;
   if(a <= b) {
     ++listen;
     b -= a;
   }
    if(listen == c) break;
    
  }
  cout << listen << endl;
}