#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A, B, T, C;
  cin >> A >> B >> T;
  C=(T-(T%A))/A;
  cout << B*C << endl;
}