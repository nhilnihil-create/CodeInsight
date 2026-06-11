#include <bits/stdc++.h>
using namespace std;

int main() {
  double a=0, b=0, x=0;
  cin >> a >> b;
  x = (a+b)/2;
  if (x - int(x) != 0){
    x = int(x) + 1;
  }
  cout << x << endl;

}
