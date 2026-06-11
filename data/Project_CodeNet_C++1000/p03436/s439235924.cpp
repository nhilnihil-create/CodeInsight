#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

struct HashPair {
  size_t operator() (const P& p) const {
    auto hash1 = hash<int>{}(p.first);
    auto hash2 = hash<int>{}(p.second);
    size_t seed = 0;
    seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    return seed;
  }
};

struct Point {
  P pos;
  int h;
  Point(P pos, P goal, int d) : pos(pos) {
    h = d + abs(goal.first - pos.first) + abs(goal.second - pos.second);
  }
  bool operator<(const Point& r) const {
    return h > r.h;
  }
};

void solve(vector<string> s) {
  int H = s.size();
  int W = s[0].length();

  unordered_map<P, bool, HashPair> closed;
  int num_white(0);
  REP(h, H)
    REP(w, W)
    if (s[h][w] == '#')
      closed[P(h + 1, w + 1)] = true;
    else
      num_white++;
  REP(h, H + 1) {
    closed[P(h, 0)] = true;
    closed[P(h, W + 1)] = true;
  }
  REP(w, W + 1) {
    closed[P(0, w)] = true;
    closed[P(H + 1, w)] = true;
  }
  unordered_map<P, P, HashPair> before;
  unordered_map<P, int, HashPair> distance;
  distance[P(1, 1)] = 1;

  priority_queue<Point> q;
  P goal(H, W);
  q.emplace(Point(P(1, 1), goal, 0));

  const vector<P> neighbors { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

  while (!q.empty()) {
    Point pnow = q.top();
    P now = pnow.pos;
    q.pop();

    if (now == goal) {
      cout << num_white - distance[now] << endl;
      return;
    }

    for (P n : neighbors) {
      P neighbor(now.first + n.first, now.second + n.second);
      if (closed[neighbor])
	continue;
      closed[neighbor] = true;
      distance[neighbor] = distance[now] + 1;
      q.emplace(Point(neighbor, goal, distance[neighbor]));
      before[neighbor] = now;
    }
  }
  cout << -1 << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W;
  cin >> H >> W;

  vector<string> s(H);
  REP(i, H)
    cin >> s[i];

  solve(move(s));

  return 0;
}
