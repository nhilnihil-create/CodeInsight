#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;
  long long N = B - A;
  cout << N * (N+1) / 2 - B << endl;
}