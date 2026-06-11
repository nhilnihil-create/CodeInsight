#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A, P, N;
  cin >> A >> P;
  N=3*A+P;
  cout << (N-(N%2))/2 << endl;
}