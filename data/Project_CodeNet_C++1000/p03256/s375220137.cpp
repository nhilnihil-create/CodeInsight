#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 200'009;

char s[N];
vector<int> g[N];
int cnt[N][2];
bool was[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    if (x == y) {
      ++cnt[x][(int)(s[x] - 'A')];
    } else {
      g[x].push_back(y);
      g[y].push_back(x);
      ++cnt[x][(int)(s[y] - 'A')];
      ++cnt[y][(int)(s[x] - 'A')];
    }
  }
  memset(was, false, sizeof was);
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    if (cnt[i][0] == 0 || cnt[i][1] == 0) {
      was[i] = true;
      a.push_back(i);
    }
  }
  int rem = n;
  while (!a.empty()) {
    vector<int> na;
    for (int x : a) {
      for (int y : g[x]) {
        if (was[y]) {
          continue;
        }
        --cnt[y][(int)(s[x] - 'A')];
        if (cnt[y][0] == 0 || cnt[y][1] == 0) {
          was[y] = true;
          na.push_back(y);
        }
      }
    }
    rem -= (int)a.size();
    a = na;
  }
  puts(rem != 0 ? "Yes" : "No");
}
