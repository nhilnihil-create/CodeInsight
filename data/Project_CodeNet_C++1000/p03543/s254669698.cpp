#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int n1, n2, n3, n4;
  n1 = N / 1000;
  n2 = N % 1000 / 100;
  n3 = N % 1000 % 100 / 10;
  n4 = N % 1000 % 100 % 10;
  if (n1 == n2 && n2 == n3) cout << "Yes" << endl;
  else if (n2 == n3 && n3 == n4) cout << "Yes" << endl;
  else cout << "No" << endl;
}