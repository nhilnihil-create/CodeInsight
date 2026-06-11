#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main () {
  int A, B, C, D, cost = 0;
  cin >> A >> B >> C >> D;
  if (A < B) cost += A;
  else cost += B;
  if (C < D) cost += C;
  else cost += D;
  cout << cost << endl;
}