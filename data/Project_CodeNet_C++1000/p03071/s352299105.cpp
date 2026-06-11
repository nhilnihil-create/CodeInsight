#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << (a>b ? 2*a-1 : a<b ? 2*b-1 : a+b);
}