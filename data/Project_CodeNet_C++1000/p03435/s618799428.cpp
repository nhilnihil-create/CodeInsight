#include <bits/stdc++.h>
using namespace std;

int main() {
  
  vector<int> cij(9);
   for (int i=0; i<9 ;i++) {
     cin >> cij.at(i) ;
   }
  
  int a, b, c, d, e, f, g, h, i, j, k, l;
  a = cij.at(1) - cij.at(0);
  b = cij.at(2) - cij.at(0);
  c = cij.at(3) - cij.at(0);
  d = cij.at(6) - cij.at(0);
  e = cij.at(4) - cij.at(3);
  f = cij.at(5) - cij.at(3);
  g = cij.at(7) - cij.at(6);
  h = cij.at(8) - cij.at(6);
  i = cij.at(4) - cij.at(1);
  j = cij.at(7) - cij.at(1);
  k = cij.at(5) - cij.at(2);
  l = cij.at(8) - cij.at(2);
  
  if (a==e && a==g && b==f && b==h && c==i && c==k && d==j && d==l){
    cout << "Yes" << endl;
  }
  
  else {
    cout << "No" << endl;
  }
  
  
}