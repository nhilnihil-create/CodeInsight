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
  if (A == B && B == C) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}