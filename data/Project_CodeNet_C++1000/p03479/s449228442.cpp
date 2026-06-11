#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll x, y, d = 0;
  cin >> x >> y;
  while (x <= y) {
    x *= 2;
    d++;
  }
  cout << d;
}
