#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int h, l;
  h = A * N;
  l = B;
  if (h < l) cout << h << endl;
  else cout << l << endl;
}