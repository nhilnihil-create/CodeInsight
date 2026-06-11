#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <cmath>
#include <utility> // pair make_pair
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits> // LLONG_MAX, LLONG_MIN, INT_MIN, INT_MAX
#include <assert.h>

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
#define int ll
#define INF INT_MAX/10
#define MOD 1000000007

using namespace std;
using Pi = pair<int, int>;
using Graph = vector<vector<int> >;
using WeightGraph = vector<vector<Pi> >;

int Input[100100];

signed main() {
  int N, K; cin >> N >> K;
  vector<vector<pair<int, int>>> G(N);
  rep(i , N) {
    int t, d; cin >> t >> d;
    t--;
    if (G[t].empty()) {
      G[t].push_back(make_pair(d, 0));
    } else {
      G[t].push_back(make_pair(d, 0));
    }
  }

  auto ps = [](const pair<int, int> & l, const pair<int, int> & r) {
              return l.first > r.first;
            };

  vector<pair<int, int>> ALL;
  rep(i, N) {
    if (!G[i].empty()) {
      sort(G[i].begin(), G[i].end(), ps);
      G[i][0].second = 1;
      rep(j, G[i].size()) {
        ALL.emplace_back(G[i][j]);
      }
    }
  }

  sort(ALL.begin(), ALL.end(), ps);
  auto pqs1 = [](const pair<int, int> &l, const pair<int, int> & r) {
               if (l.second == r.second) {
                 return l.first > r.first;
               } else {
                 return l.second > r.second;
               }
             };

  auto pqs2 = [](const pair<int, int> &l, const pair<int, int> & r) {
               if (l.second == r.second) {
                 return l.first < r.first;
               } else {
                 return l.second < r.second;
               }
             };


  priority_queue<Pi, vector<Pi>, decltype(pqs1)> Using(pqs1);
  priority_queue<Pi, vector<Pi>, decltype(pqs2)> Unused(pqs2);


  // initialize
  int cnt = 0;
  int X = 0;
  int Y = 0;
  for (auto &p: ALL) {
    if (cnt < K) {
      X += p.first;
      Y += p.second;
      Using.push(p);
      cnt++;
    } else {
      Unused.push(p);
    }
  }

  int ans = X + Y*Y;

  while (!Unused.empty() && Unused.top().second == 1 && Using.top().second == 0) {
    Pi p1 = Unused.top(); Unused.pop();
    Pi p2 = Using.top(); Using.pop();
    X += p1.first - p2.first;
    Y += 1;
    ans = max(ans, X + Y*Y);
  }

  cout << ans << endl;
  return 0;
}
