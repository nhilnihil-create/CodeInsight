#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  N *= A;
  if(N < B) cout << N << endl;
  else cout << B << endl;
}