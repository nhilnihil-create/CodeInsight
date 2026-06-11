#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C;
  D=(B-(B%A))/A;
  cout << min(C,D) << endl;
}