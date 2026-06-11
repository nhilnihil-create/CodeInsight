#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int N,A,B,x,y;
  
  cin >> N >> A >> B;
  
  y = N * A;
  
  if (y > B) {
    x = B;
  }
  else {
    x = y;
  }
  
  cout << x << endl;
}