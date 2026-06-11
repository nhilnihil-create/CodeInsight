#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<vector<ll>> matrix;

string g[305];
char ret[305][305];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> g[i];
  int ans = 0;
  for(int plus = 0; plus < n; plus++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        ret[i][(j+plus)%n] = g[i][j];
      }
    }
    bool good = true;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < i; j++) {
        if(ret[i][j] != ret[j][i]) {
          good = false;
        }
      }
    }
    if(good) ans += n;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
