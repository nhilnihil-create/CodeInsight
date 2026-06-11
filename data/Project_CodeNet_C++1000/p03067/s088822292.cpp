#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int a, c, B;
  cin >> a >> c >> B;
  int A = min(a, c);
  int C = max(a, c);
  if(A <= B && B <= C) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
