#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (abs(C - A) + abs(C - B) == abs(B - A)) cout << "Yes" << endl;
  else cout << "No" << endl;
}