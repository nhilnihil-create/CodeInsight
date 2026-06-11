#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

const double pi = 3.141592653589793;
// -------------------------------------------------------

int N;
int F[110][6][3];
int P[110][20];
int open[6][3];
int overlap[110];

int main() {
  cin >> N;
  repe(i, 1, N) {
    repe(j, 1, 5) {
      repe(k, 1, 2) {
        cin >> F[i][j][k];
        if (F[i][j][k] == 1) {
          open[j][k]++;
        }
      }
    }
  }
  repe(i, 1, N) {
    repe(j, 0, 10) { cin >> P[i][j]; }
  }

  int ans = -inf;
  for (int bit = 1; bit < (1 << 10); ++bit) {
    repe(i, 0, N) { overlap[i] = 0; }

    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 2; ++j) {
        int ij = 2 * i + j;
        if ((1 << ij) & bit) {
          for (int k = 1; k <= N; ++k) {
            if (F[k][i + 1][j + 1] == 1) {
              overlap[k]++;
            }
          }
        }
      }
    }

    int score = 0;
    repe(i, 1, N) { score += P[i][overlap[i]]; }
    chmax(ans, score);
  }
  cout << ans << endl;
}
