#include <bits/stdc++.h>
#include <iomanip>
#define ll long long
using namespace std;

int main() {
  ll X, Y, cnt = 0;
  cin >> X >> Y;
  while(X <= Y) {
    X *= 2;
    cnt++;
  }
  cout << cnt << endl;
}
