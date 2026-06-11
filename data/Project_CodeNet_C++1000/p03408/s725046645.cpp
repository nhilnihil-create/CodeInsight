#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, j, i;
  cin >> a;
  c=0;
  vector<string> blue(100);
  for(i=0;i<a;i++) {
    cin >> blue.at(i);
  }
  cin >> b;
   vector<string> red(100);
  for(i=0;i<b;i++) {
    cin >> red.at(i);
  }
  for(i=0;i<a;i++) {
    d=0;
    for(j=0;j<100;j++) {
      if(blue.at(i) == blue.at(j)) {
        d++;
      }
      if(blue.at(i) == red.at(j)) {
        d--;
      }
         }
         if (d > c) {
           c=d;
         }
         }
         cout << c << endl;
         }