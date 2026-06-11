#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int hp;
  cin >> hp;
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    hp = gcd(hp, a);
  }

  cout << hp << endl;
  return 0;
}
