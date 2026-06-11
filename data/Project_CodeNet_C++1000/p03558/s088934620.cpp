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
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int d; cin >> d;
  vector<int> cost(d, INF);
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que; // cost, num
  que.emplace(0, 1);
  cost[1] = 0;
  while (!que.empty()) {
    auto a = que.top(); que.pop();
    if (cost[a.second] < a.first) continue;
    if (a.second == 0) {
      cout << cost[0] + 1 << '\n';
      return 0;
    }
    int mul10 = (a.second * 10) % d, plus1 = (a.second + 1) % d;
    if (cost[mul10] > a.first) {
      cost[mul10] = a.first;
      que.emplace(a.first, mul10);
    }
    if (cost[plus1] > a.first + 1) {
      cost[plus1] = a.first + 1;
      que.emplace(a.first + 1, plus1);
    }
  }
}
