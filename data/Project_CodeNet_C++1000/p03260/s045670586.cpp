#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int A, B;
  cin >> A >> B;
  cout << (A * B % 2 == 1 ? "Yes" : "No") << endl;
}