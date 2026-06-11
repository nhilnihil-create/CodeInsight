#pragma GCC diagnostic ignored "-Wunused-result"
#define NDEBUG

#include <algorithm>
#include <cassert>
#include <cinttypes>
#include <cstdio>
#include <tuple>
#include <vector>
#include <set>
#include <queue>

#ifdef NDEBUG
#  define debug(...)
#else
#  define debug(...)                                \
  do {                                              \
    fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
    fprintf(stderr, __VA_ARGS__);                   \
    fputc('\n', stderr);                            \
  } while (false)
#endif

using namespace std;
using tii = tuple<int, int>;

const int MAX = 2e5;
int N, M;
char s[MAX+1];
vector<int> adj[MAX];
bool v[MAX];

int main() {
  scanf("%d %d %s", &N, &M, s);
  for (int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  for (int i = 0; i < N; i++) {
    bool a = false, b = false;
    for (int j: adj[i]) {
      if (s[j] == 'A') a = true;
      else b = true;
    }
    if (!(a && b)) q.push(i);
  }
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    v[i] = true;
    for (int j: adj[i]) {
      if (!v[j]) {
        bool a = false, b = false;
        for (int j2: adj[j]) {
          if (!v[j2]) {
            if (s[j2] == 'A') a = true;
            else b = true;
          }
        }
        if (!(a && b)) q.push(j);
      }
    }
  }
  bool ans = false;
  for (int i = 0; i < N; i++) if (!v[i]) ans = true;
  puts(ans ? "Yes" : "No");
  return 0;
}
