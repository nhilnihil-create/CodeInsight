#include <bits/stdc++.h>
#define double long double
using namespace std;

constexpr int N = 303, M = 310;
double ev[M][M][M];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  int a[4] = {0, 0, 0, 0};
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[x] += 1;
  }

  for(int k = 0; k < N; ++k) {
    for(int j = 0; j < N; ++j) {
      for(int i = 0; i < N; ++i) {
        if(!i && !j && !k) continue;
        double sum = n;
        if(i) sum += (double) i * ev[i - 1][j][k];
        if(j) sum += (double) j * ev[i + 1][j - 1][k];
        if(k) sum += (double) k * ev[i][j + 1][k - 1];
        ev[i][j][k] = sum / (i + j + k);
      }
    }
  }
  cout << setprecision(12) << fixed << ev[a[1]][a[2]][a[3]] << '\n';
}