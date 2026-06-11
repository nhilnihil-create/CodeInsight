#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int num = min(B / A, C);
  cout << num;
}