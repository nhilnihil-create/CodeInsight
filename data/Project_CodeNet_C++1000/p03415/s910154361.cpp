#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  vector<string> c(3);
  rep(i, 3) cin >> c[i];
  rep(i, 3) cout << c[i][i];
  cout << endl;
}