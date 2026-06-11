#include <cstdio>
#include <queue>

#define int long long
#define dotimes(i, n) for (int i : range(n))

using namespace std;

class range {
  class iterator {
    int i, s;
  public:
    iterator(int i, int s): i(i), s(s) {}
    int& operator*() {
      return i;
    }
    void operator++() {
      i += s;
    }
    bool operator!=(iterator const& that) {
      return i < that.i;
    }
  };
  iterator b, e;
public:
  range(int e): b({0, 1}), e({e, 1}) {}
  range(int b, int e): b({b, 1}), e({e, 1}) {}
  range(int b, int e, int s): b({b, s}), e({e, s}) {}
  iterator begin() {
    return b;
  }
  iterator end() {
    return e;
  }
};

int rint() {
  int n;
  scanf("%lld", &n);
  return n;
}

void wint(int n) {
  printf("%lld\n", n);
}

template<typename T>
inline int size(T container) {
  return static_cast<int>(container.size());
}

template<typename T>
inline bool maxs(T& a, T const& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
inline bool mins(T& a, T const& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

signed main() {
  const int H = rint();
  const int W = rint();
  int c = 0;
  bool board[H+2][W+2] = {};
  dotimes(j, H) {
    char s[W+1];
    scanf("%s\n", s);
    dotimes(i, W)
      if (s[i] == '.') {
        c++;
        board[j+1][i+1] = 1;
      }
  }
  int sp[H][W] = {};
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  sp[0][0] = 1;
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int j = p.first, i = p.second, d = sp[j][i] + 1;
    const int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
    dotimes(k, 4) {
      int y = j + dy[k], x = i + dx[k];
      if (board[y+1][x+1] && !sp[y][x]) {
        q.emplace(y, x);
        sp[y][x] = d;
      }
    }
  }
  if (sp[H-1][W-1])
    wint(c - sp[H-1][W-1]);
  else
    wint(-1);
  return 0;
}
