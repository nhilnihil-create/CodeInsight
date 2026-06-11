#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  vector<ll> D(5, 0);
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];
  
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    char f = S[i][0];
    if (f == 'M') D[0]++;
    if (f == 'A') D[1]++;
    if (f == 'R') D[2]++;
    if (f == 'C') D[3]++;
    if (f == 'H') D[4]++;
  }
  
  ll ans = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
      for (int k = j + 1; k < 5; k++) {
        ans += D[i] * D[j] * D[k];
      }
    }
  }
  cout << ans << endl;
}