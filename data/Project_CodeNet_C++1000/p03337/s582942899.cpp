#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, r=0;
  cin >> a >> b;
  
  if (a-b <= a+b && a*b <= a+b) r = a+b;
  if (a+b <= a-b && a*b <= a-b) r = a-b;
  if (a+b <= a*b && a-b <= a*b) r = a*b;
  cout << r << endl;
}