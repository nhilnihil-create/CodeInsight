#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  if ((A < C && C < B) || (A > C && C > B))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}