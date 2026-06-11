#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int ans = min(A*N, B);
  cout << ans << endl;
}
