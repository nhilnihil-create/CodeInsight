#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int C[N-1],S[N-1],F[N-1];
  for (int i = 0; i < N-1; i++) {
    cin >> C[i] >> S[i] >> F[i];
  }
  for (int i = 0; i < N-1; i++) {
    int now = 0;
    for (int j = i; j < N-1; j++) {
      if (now < S[j]) {
        now = S[j] + C[j];
      } else {
        now += ((F[j] - (now % F[j])) % F[j]) + (C[j]);
      }
    }
    cout << now << endl;
  }
  cout << 0 << endl;
  return 0;
}