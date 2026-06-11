#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,A,B;
  cin >> N >> A >> B;
  int res;
  if (N*A < B) res = N*A;
  else res = B;
  cout << res << endl;
}