#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int b,c,d;
  b=a%10;
  c=(a-b)%100/10;
  d=(a-b-c*10)/100;
  cout << b+c+d << endl;
}
