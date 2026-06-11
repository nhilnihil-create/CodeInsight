#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  double res = 0;
  rep(i,n) {
    double m;
    string s;
    cin >> m >> s;
    if (s == "JPY") res += m;
    if (s == "BTC") res += m * 380000;
  }
  cout << fixed << setprecision(10);
  cout << res << endl;
  return 0;
}