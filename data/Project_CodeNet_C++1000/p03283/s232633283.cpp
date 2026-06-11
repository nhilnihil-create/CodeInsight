#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007

bool dbgflag = true;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, Q;
  cin >> N >> M >> Q;

  vector<vector<int>>trains(N+1, vector<int>(N+1, 0));
  for (int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    trains[l][r]++;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      trains[i][j] += trains[i-1][j] + trains[i][j-1] - trains[i-1][j-1];
    }
  }

  for (int i = 0; i < Q; i++) {
    int p, q;
    cin >> p >> q;
    cout << trains[q][q] - trains[p-1][q] - trains[q][p-1] + trains[p-1][p-1] << endl;
  }
}
