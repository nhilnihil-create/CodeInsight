#include<iostream>
using namespace std;

int main(){
  int a, b, c, d, e;
  cin >> a >> b;
  c = a + b;
  d = a - b;
  e = a * b;
  cout << max(c, max(d, e));
}