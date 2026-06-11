#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using ULL = uint64_t;
using P = pair<LL, LL>;
#define rep(i, n) for (LL i = 0; i < (n); ++i)
//#define DEBUG


#define HUGE (9999999LL)
LL dfs(const LL depth, const LL d, const LL g,
       const vector<LL> &p, const vector<LL> &c,
       vector<LL> &completed) {
  if (depth == d) {
    LL cost = 0;
    LL point = 0;
    rep(i, d) {
      // completed i
      if (completed.at(i) == 1) {
        point += (i + 1) * 100 * p.at(i) + c.at(i);
        cost += p.at(i);
      }
    }
//    cout << depth << " : " << cost << " : " << point << endl;
    if (point >= g) {
      return cost;
    }
//    cout << cost << endl;
    for (int i = d - 1; i >= 0; --i) {
      if (completed.at(i) == 0) {
        if ((i + 1) * 100 * (p.at(i) - 1) < g - point) {
          return HUGE; // infeasible
        }
        cost += (g - point) / ((i + 1) * 100);
        cost += ((g - point) % ((i + 1) * 100) ? 1 : 0);
        return cost;
      }
    }
    abort(); // cannot happen
  }

  LL min_cost = HUGE;
  rep(i, 2) {
    completed.at(depth) = i;
    min_cost = min(min_cost, dfs(depth + 1, d, g, p, c, completed));
  }
  return min_cost;
}


int main() {
  LL d, g;
  cin >> d >> g;
  vector<LL> p(d, -1);
  vector<LL> c(d, -1);
  rep(i, d) {
    cin >> p.at(i) >> c.at(i);
  }
  
  vector<LL> completed(d, -1);
  cout << dfs(0, d, g, p, c, completed) << endl;

  
  #ifdef DEBUG
  cout << "D: " << d << endl;
  cout << "G: " << g << endl;
  #endif
}

