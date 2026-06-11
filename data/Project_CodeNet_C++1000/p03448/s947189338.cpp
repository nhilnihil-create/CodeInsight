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
    for (int b = 0; b <= B; b++) {
      int part = a * 500 + b * 100;
      if (X >= part && X - part <= C * 50) ++res;
    }
  }
  cout << res << endl;

  return 0;
}