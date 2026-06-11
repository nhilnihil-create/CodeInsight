#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  if(A + B + C + D == 21 && A * B * C * D == 252) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}