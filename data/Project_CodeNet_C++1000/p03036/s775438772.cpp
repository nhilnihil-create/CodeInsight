#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  long long r, d, x;
  cin >> r >> d >> x;

  for (int i = 0; i < 10; i++) {
    x = r * x - d;
    cout << x << endl;
  }
}