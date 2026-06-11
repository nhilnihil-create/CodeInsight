//This template belongs to Juan Carlo Vieri
#include <bits/stdc++.h>
using namespace std;

typedef int_fast64_t ll;
typedef long double ld;
typedef int_fast64_t intt;
typedef int_fast64_t tmp_m;
#define deb(x) cout << #x << ' ' << x << endl
#define rep(i, cmp1, cmp2) for (tmp_m i = cmp1; i < cmp2; ++i)
#define repp(i, cmp1, cmp2) for (tmp_m i = cmp1; i >= cmp2; --i)
#define pb push_back
#define st stack
#define pa pair
#define vc vector
#define qu queue
#define pq priority_queue
#define fr first
#define sc second
#define mp map
const ld pi = acos(-1.0);
const intt mod = 1e9 + 7;

struct pr {
  intt x;
  intt y;
  intt dst;
  pr() {}
  pr(intt x, intt y, intt dst) : x(x), y(y), dst(dst) {}
  inline bool operator<(const pr& cmp2) const {
    if (dst != cmp2.dst) return dst < cmp2.dst;
    if (x != cmp2.x) return x < cmp2.x;
    return y < cmp2.y;
  }
  inline bool operator==(const pr& cmp2) const {
    return (cmp2.dst == dst) && (cmp2.x == x) && (cmp2.y == y);
  }
  inline bool operator>(const pr& cmp2) const {
    if (dst != cmp2.dst) return dst > cmp2.dst;
    if (x != cmp2.x) return x > cmp2.x;
    return y > cmp2.y;
  }
};

struct point {
  intt x;
  intt y;
  point() {}
  point(intt x, intt y) : x(x), y(y) {}
  inline bool operator<(const point& cmp2) const {
    if (cmp2.x != x) return cmp2.x < x;
    return cmp2.y < y;
  }
  inline bool operator==(const point& cmp2) const {
    return (cmp2.x == x) && (cmp2.y == y);
  }
  inline bool operator>(const point& cmp2) const {
    if (cmp2.x != x) return cmp2.x > x;
    return cmp2.y > y;
  }
};

class prHash {
 public:
  size_t operator()(const pr& cmp1) const {
    return (hash<intt>()(cmp1.x)) ^ (hash<intt>()(cmp1.y)) ^
           (hash<intt>()(cmp1.dst));
  }
};

class pointHash {
 public:
  size_t operator()(const point& cmp1) const {
    return (hash<intt>()(cmp1.x)) ^ (hash<intt>()(cmp1.y));
  }
};

inline bool spoint(const point& cmp1, const point& cmp2) {
  // swap(cmp1, cmp2);
  if (cmp1.x != cmp2.x) return cmp1.x < cmp2.x;
  return cmp1.y < cmp2.y;
}

inline bool spr(const pr& cmp1, const pr& cmp2) {
  // swap(cmp1, cmp2);
  if (cmp1.dst != cmp2.dst) return cmp1.dst < cmp2.dst;
  if (cmp1.x != cmp2.x) return cmp1.x < cmp2.x;
  return cmp1.y < cmp2.y;
}

void solve() {
  intt a, b, q;
  cin >> a >> b >> q;
  vc<intt> s(a), t(b);
  rep(i, 0, a)cin >> s[i];
  rep(i, 0, b)cin >> t[i];
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  while(q--){
    intt x;
    cin >> x;
    intt sright = s[upper_bound(s.begin(), s.end(), x) - s.begin()];
    intt sleft = -1e18;
    if(upper_bound(s.begin(), s.end(), x) - s.begin() > 0){
      sleft = s[upper_bound(s.begin(), s.end(), x) - s.begin() - 1];
    }
    intt tright = t[upper_bound(t.begin(), t.end(), x) - t.begin()];
    intt tleft = -1e18;
    if(upper_bound(t.begin(), t.end(), x) - t.begin() > 0){
      tleft = t[upper_bound(t.begin(), t.end(), x) - t.begin() - 1];
    }
    intt ans = min(abs(sright - x), abs(tright - x)) + abs(tright - sright);
    ans = min(ans, min(abs(sleft - x), abs(tright - x)) + abs(tright - sleft));
    ans = min(ans, min(abs(sleft - x), abs(tleft - x)) + abs(tleft - sleft));
    ans = min(ans, min(abs(sright - x), abs(tleft - x)) + abs(tleft - sright));
    cout << ans << endl;
  }
}

void init() {
  // remove if interactive
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(0));
  // memset(dp, -1, sizeof dp);
}

int main() {
  init();
  solve();
  return 0;
}
