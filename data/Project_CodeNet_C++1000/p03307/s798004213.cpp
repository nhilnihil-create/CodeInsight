#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  if (N % 2 == 0)
    cout << N << endl;
  else
    cout << 2 * N << endl;
}
