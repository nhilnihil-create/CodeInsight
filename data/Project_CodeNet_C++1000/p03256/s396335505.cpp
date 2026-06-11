#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
  #define debug(...) printf(__VA_ARGS__)
#else
  #define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN = 2e5 + 100;
char S[MAXN];
VI e[MAXN];

int cnt[MAXN][2];
bool out[MAXN];

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  scanf("%s", S);
  for (int i = 0; i < M; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    e[x].PB(y);
    e[y].PB(x);
  }
  for (int i = 0; i < N; i++) {
    for (int u : e[i])
      cnt[i][S[u] - 'A']++;
  }
  VI bad;
  for (int i = 0; i < N; i++)
    if (cnt[i][0] == 0 || cnt[i][1] == 0) {
      out[i] = true;
      bad.PB(i);
    }
  while (!bad.empty()) {
    int t = bad.back();
    bad.pop_back();
    for (int u : e[t]) {
      if (out[u])
        continue;
      cnt[u][S[t] - 'A']--;
      if (cnt[u][0] == 0 || cnt[u][1] == 0) {
        out[u] = true;
        bad.PB(u);
      }
    }
  }
  bool good = false;
  for (int i = 0; i < N; i++)
    if (!out[i])
      good = true;
  puts(good ? "Yes" : "No");
  return 0;
}
