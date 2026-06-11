#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B;
  cin >> A >> B;

  if (A * B % 2 == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}