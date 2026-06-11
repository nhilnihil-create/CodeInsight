#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll h, w, n, m;
  cin >> h >> w >> n >> m;
  cout << h*w - n*w - m*h + n*m << endl;
}