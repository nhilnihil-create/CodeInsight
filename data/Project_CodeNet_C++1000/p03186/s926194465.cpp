#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
  int64_t A, B, C;
  cin >> A >> B >> C;
  if (A+B+1>=C) {
    cout << B+C << endl;
  }
  else {
    cout << A+2*B+1 << endl;
  }
}