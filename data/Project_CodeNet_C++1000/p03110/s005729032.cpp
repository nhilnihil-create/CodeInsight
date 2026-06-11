#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  double total = 0;
  for(int i=0; i<n; i++) {
    double x;
    string y;
    cin >> x >> y;
    if(y == "JPY") total += x;
    else total += x*380000;
  }
  cout << fixed << setprecision(6) << total << endl;
  return 0;
}