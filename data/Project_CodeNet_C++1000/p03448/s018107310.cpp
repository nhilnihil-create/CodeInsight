#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;
  int res = 0;
  for (int a = 0; a <= A; a++) {
    int rem = X - a * 500; // 残金
    // 区間の上端 - 区間の下端
    res += max(0, min(rem / 100 + 1, B + 1)) - max(0, min((rem - (C - 1) * 50) / 100, B + 1));
  }
  cout << res << endl;

  return 0;
}