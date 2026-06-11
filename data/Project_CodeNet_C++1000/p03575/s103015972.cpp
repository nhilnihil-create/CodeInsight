#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

int N, M;
int a[100], b[100];
bool used[100];

vector<int> Graph[100];

void initgraph() {
  rep(i, 0, 100) {
    Graph[i] = vector<int>();
    used[i] = false;
  }
}

void bfs() {
  queue<int> que;

  que.push(1);
  used[1] = true;

  while (!que.empty()) {
    int cv = que.front();
    que.pop();

    for (auto nv : Graph[cv]) {
      if (!used[nv]) {
        que.push(nv);
        used[nv] = true;
      }
    }
  }
}

bool is_connected() {
  repe(i, 1, N) {
    if (!used[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> N >> M;
  repe(i, 1, M) { cin >> a[i] >> b[i]; }

  int ans = 0;
  repe(i, 1, M) {
    initgraph();
    repe(j, 1, M) {
      if (j == i) continue;

      int aa = a[j];
      int bb = b[j];
      Graph[aa].push_back(bb);
      Graph[bb].push_back(aa);
    }
    bfs();

    if (!is_connected()) {
      ++ans;
    }
  }

  cout << ans << endl;
}