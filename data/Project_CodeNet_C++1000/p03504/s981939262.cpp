#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define MAX 100010
#define MAX_C 31

int n, C;
int s[MAX], t[MAX], c[MAX];
int imos[MAX_C][MAX];

void init_imos() {
  for (int i = 0; i <= C; i++) {
    for (int j = 0; j < MAX; j++) {
      imos[i][j] = 0;
    }
  }
}

void use_imos() {
  for (int i = 1; i <= C; i++) {
    for (int j = 1; j < MAX; j++) {
      imos[i][j] += imos[i][j - 1];
    }
  }
}

int solve() {
  int max_overlap = 0;
  for (int j = 0; j < MAX; j++) {
    int count = 0;
    for (int i = 1; i <= C; i++) {
      if (imos[i][j]) count++;
    }
    max_overlap = max(max_overlap, count);
  }
  return max_overlap;
}

signed main() {
  cin >> n >> C;
  init_imos();
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> t[i] >> c[i];
    imos[c[i]][s[i]]++;
    imos[c[i]][t[i] + 1]--;
  }
  use_imos();
  cout << solve() << endl;
  return 0;
}