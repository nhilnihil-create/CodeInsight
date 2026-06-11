#include<iostream>
using namespace std;

int main() {
  int n,a,b,min,max;
  cin >> n >> a >> b;
  if(a >= b) max = b;
  else max = a;
  if(a + b <= n) min = 0;
  else min = a + b - n;
  cout << max << " " << min;
  return 0;
}