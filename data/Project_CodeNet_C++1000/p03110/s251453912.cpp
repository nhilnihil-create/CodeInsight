#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  long double ans = 0.00000000;
  long double coin = 0.00000000;
  for (int i = 0; i < N; i++) {
    long double x;
    cin >> x;
    string tmp;
    cin >> tmp;
    if (tmp == "JPY") ans += x;
    else coin += x;
  }
  cout << ans + coin*380000.0 << endl;
}
