#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A,B,ans;
  cin >> A >> B;
  ans = (A + B) / 2 + (A + B) % 2;
  cout << ans << endl;
}
