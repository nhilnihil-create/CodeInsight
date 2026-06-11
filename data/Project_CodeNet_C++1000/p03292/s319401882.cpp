#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  int x = abs(B-A) + abs(C-B), y = abs(C-B) + abs(A-C), z = abs(A-C) + abs(B-A);
  
  cout << min({x, y, z}) << endl;
  
}