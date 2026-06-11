#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
  int N; cin >> N;

  Graph G(N, vector<int>(N,1));
  int M;

  if (N % 2 == 0) {
    M = N * (N-2) / 2;
    rep(i,N) {
      G[i][i] = 0;
      G[i][N-1-i] = 0;
    }
  } else {
    M = N * (N-1) / 2 - N / 2;
    rep(i,N) {
      G[i][i] = 0;
      if (i != N-1) G[i][N-2-i] = 0;
    }
  }

  cout << M << endl;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (G[i][j]) cout << i+1 << " " << j+1 << endl;
    }
  }
}