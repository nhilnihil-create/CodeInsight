#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007

bool dbgflag = false; //debug

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<vector<int>> adjlist(10, vector<int>(10));

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> adjlist[i][j];
    }
  }

  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        adjlist[i][j] = min(adjlist[i][j], adjlist[i][k] + adjlist[k][j]);
      }
    }
  }
  if (dbgflag) cout << "warshallfloyd" << endl;

  int cost = 0;
  //vector<vector<int>> wall(h, vector<int>(w));
  /*for (int i = 0; i < w*h; i++) {
    int a;
    cin >> a;
    cost += adjlist[a][1];
  }*/
  if (dbgflag) cout << h << " " << w << endl;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int a;
      cin >> a;
      if (a == -1) continue;
      cost += adjlist[a][1];
    }
  }

  cout << cost << endl;
}
