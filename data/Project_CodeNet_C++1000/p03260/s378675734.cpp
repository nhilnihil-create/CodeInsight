#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int A,B;
  cin >> A >> B;
  if (A % 2 != 0 && B % 2 != 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}