#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  if(A * N < B) cout << A * N;
  else cout << B;
  return 0;
}

