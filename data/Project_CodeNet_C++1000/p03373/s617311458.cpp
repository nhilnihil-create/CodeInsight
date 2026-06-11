#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  long long cost = 0;
  while(x > 0 && y > 0){
    cost += min(a+b, 2*c);
    x--;
    y--;
  }
  if(x == 0 && y > 0) 
    cost += min(b, 2*c) * y;
  else if(x > 0 && y == 0) 
    cost += min(a, 2*c) * x;
  cout << cost << endl;
}