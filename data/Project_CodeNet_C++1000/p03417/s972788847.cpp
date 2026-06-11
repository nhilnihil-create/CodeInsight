#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  ll n, m;
  cin >> n >> m;

  if (!(n == 1 || m == 1))
    cout << n * m - (n * 2 + m * 2) + 4 << endl;
  else if (n == 1 && m == 1)
    cout << 1 << endl;
  else
    cout << max(m, n) - 2 << endl;
}