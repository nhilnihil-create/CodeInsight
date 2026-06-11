#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c ;
  cin >> a >> b;
  c=max(a,b) ;
  cout << (2*c<=16 ? "Yay!":":(" ) << endl;
}