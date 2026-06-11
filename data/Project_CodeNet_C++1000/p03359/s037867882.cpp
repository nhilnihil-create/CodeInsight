#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  cout << A - 1 + min(B/A,1) << endl;
}
