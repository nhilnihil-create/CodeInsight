#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll grid[1010][1010];

int main() {
  // std::cout << std::fixed << std::setprecision(10);

  ll H, W;
  scanf("%lld %lld", &H, &W);

  for (ll y = 0; y < H; y++) {
    string s;
    cin >> s;
    for (ll x = 0; x < W; x++) {
      ll v;
      if (s[x] == '#') {
        v = -1;  // 壁
      } else {
        v = 0;
      }
      grid[y][x] = v;
    }
  }
  grid[0][0] = 1;

  for (ll y = 0; y < H; y++) {
    for (ll x = 0; x < W; x++) {
      if (grid[y][x] == -1) {
        continue;
      }

      if (grid[y][x + 1] >= 0) {
        grid[y][x + 1] += grid[y][x];
        grid[y][x + 1] %= MOD;
      }
      if (grid[y + 1][x] >= 0) {
        grid[y + 1][x] += grid[y][x];
        grid[y + 1][x] %= MOD;
      }
    }
  }

  cout << (grid[H - 1][W - 1]) << endl;
}
