#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int b = a/100;
  int c = a%100/10;
  int d = a%10;
  int count = 0;
  if (b == 1) count++;
  if (c == 1) count++;
  if (d == 1) count++;
  cout << count << endl;
}
  