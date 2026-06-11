#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  vector<double> x(n);
  vector<string> u(n);
  double sum = 0;
  rep(i, n) {
    cin >> x[i];
    cin >> u[i];
  }
  rep(i, n) {
    if(u[i] == "BTC") {
      sum += x[i]*380000.0;
    }
    sum += x[i];
  }
  cout << sum << endl;
  return 0;
}