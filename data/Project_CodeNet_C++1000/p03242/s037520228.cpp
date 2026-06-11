#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  string n;
  cin >> n;
  for (int i = 0; i < n.size(); i++) {
    if (n[i] == '1')
      n[i] = '9';
    else if (n[i] == '9')
      n[i] = '1';
  }
  cout << n << endl;
}
