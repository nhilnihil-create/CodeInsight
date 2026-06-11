#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1010;
const int K = 31;
int n, x[N], y[N];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char direction[] = "DURL";

bool valid(ll X, ll Y, int S) {
  if (!X && !Y) return 1;
  return ((X + Y) & 1) &&
         (-S + 1 <= abs(X) + abs(Y) && abs(X) + abs(Y) <= S - 1);
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  scanf("%d", &n);
  int parity = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
    parity |= 1 << ((x[i] + y[i]) & 1);
  }

  if (parity == 3) {
    puts("-1");
    return 0;
  }

  vector<int> d(K);
  for (int i = 0; i < K; ++i) d[i] = 1 << i;

  if (parity == 1) {
    d.push_back(1);
    for (int i = 1; i <= n; ++i) --x[i];
  }

  printf("%d\n", d.size());
  for (int x : d) printf("%d ", x);
  puts("");

  for (int j = 1; j <= n; ++j) {
    ll X = x[j], Y = y[j];
    string S = parity == 1 ? "R" : "";

    for (int i = K - 1; i >= 0; --i) {
      for (int k = 0; k < 4; ++k) {
        ll XX = X + dx[k] * d[i];
        ll YY = Y + dy[k] * d[i];

        if (valid(XX, YY, d[i])) {
          X = XX, Y = YY;
          S += direction[k];
          break;
        }
      }
    }

    reverse(S.begin(), S.end());
    printf("%s\n", S.c_str());
  }

  return 0;
}
