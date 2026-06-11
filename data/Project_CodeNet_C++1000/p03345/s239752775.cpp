#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  ll A,B,C,K;
  cin >> A >> B >> C >> K;
  if (K % 2 == 0) {
    cout << A - B << endl;
  } else {
    cout << B - A << endl;
  }
  return 0;
}