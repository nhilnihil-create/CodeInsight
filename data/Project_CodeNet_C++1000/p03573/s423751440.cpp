#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int A,B,C;
  cin >> A >> B >> C;
  if (A == B) {
    cout << C << endl;
  } else if (B == C) {
    cout << A << endl;
  } else {
    cout << B << endl;
  }
  return 0;
}