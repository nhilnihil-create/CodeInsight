#include <bits/stdc++.h>
using namespace std;

int main() {
  double a=0, b=0, c=0;
  int d=0;
  cin >> a >> b;
  c = (a+b)/2;
  d = (a+b)/2;
  if(c-d>0){
    d++;
  }
  cout << d << endl;
}