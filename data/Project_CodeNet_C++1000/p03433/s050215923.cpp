#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  N %= 500;
  cout << ((N <= A) ? "Yes" : "No") << "\n";
}