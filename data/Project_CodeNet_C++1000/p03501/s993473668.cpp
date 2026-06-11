#include <bits/stdc++.h>

using namespace std;

int main() {
  // n= 時間 a= 料金(1h) b= 固定料金
  int n, a, b;
  int p;
  
  cin >> n >> a >> b;

  p = n * a;

  if (p > b) cout << b << endl;
  if (p < b) cout << p << endl;
  if (p == b) cout << b << endl;

  return(0);
}