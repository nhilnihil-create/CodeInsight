#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int b;
  cin >> a >> b;
  double p = (a + b) % 2;
  if(p == 1){
  	p / 2;
  }
  double x = (a + b) / 2 + p;
  if(1 - p == 1){
  	x = x - 1;
  }
  cout << x + 1 - p << endl;
}