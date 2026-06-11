#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
vector<vector<int> > edge(100000);
int color[100000];
bool used[100000];

bool dfs(int ver, int clr) {
  color[ver] = clr;
  used[ver] = true;
  for (int e : edge[ver]) {
    if (color[e] == clr) return true;
    else if (color[e] == 0 && dfs(e, -clr)) return true;
  }
  return false;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  long long n, m; cin >> n >> m;
  REP(i, m) {
    int a, b; cin >> a >> b;
    --a;
    --b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  REP(i, n) if (!used[i]) {
    if (dfs(i, 1)) {
      cout << n * (n - 1) / 2 - m  << '\n';
      return 0;
    }
  }
  long long black = 0, white = 0;
  REP(i, n) {
    if (color[i] == 1) ++black;
    else ++white;
  }
  cout << black * white - m << '\n';
  return 0;
}
