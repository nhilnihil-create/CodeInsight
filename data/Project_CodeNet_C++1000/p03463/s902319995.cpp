#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,A,B;
  cin >> N >> A >> B;
  if ((B - A) % 2 == 1) {
    cout << "Borys" << endl;
  } else {
    cout << "Alice" << endl;
  }
  return 0;
}