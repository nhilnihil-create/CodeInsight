#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  cout << min(A, B) << " " << max(0, A + B - N) << endl;
  return 0;
}