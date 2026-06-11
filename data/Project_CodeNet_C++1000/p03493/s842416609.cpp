#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  cin >> A;
  cout << A % 2 + A / 10 % 2 + A / 100 % 2 <<endl;
}